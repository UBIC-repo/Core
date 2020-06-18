#include <openssl/ossl_typ.h>
#include <openssl/evp.h>
#include <openssl/ec.h>
#include <openssl/err.h>
#include "VerifySignature.h"
#include "../Wallet.h"
#include "ECCtools.h"

bool VerifySignature::verify(unsigned char* msg, size_t mlen, unsigned char* sig, size_t slen, EVP_PKEY* pkey)
{
    EVP_MD_CTX *mdctx = EVP_MD_CTX_create();
    /* Initialize `key` with a public key */
    EVP_DigestVerifyInit(mdctx, NULL, EVP_sha256(), NULL, pkey);

    /* Initialize `key` with a public key */
    EVP_DigestVerifyUpdate(mdctx, msg, mlen);

    if(1 == EVP_DigestVerifyFinal(mdctx, sig, slen))
    {
        EVP_MD_CTX_free(mdctx);
        return true;
    }
    else
    {
        BIO *bio_out;
        bio_out = BIO_new_fp(stdout, BIO_NOCLOSE);
        ERR_print_errors(bio_out);
        EVP_MD_CTX_free(mdctx);
        return false;
    }
}

bool VerifySignature::verify(std::vector<unsigned char> msg, std::vector<unsigned char> signature, EVP_PKEY* pkey) {
    return VerifySignature::verify(msg.data(), msg.size(), signature.data(), signature.size(), pkey);
}

bool VerifySignature::verify(std::vector<unsigned char> msg, std::vector<unsigned char> signature, std::vector<unsigned char> pubKey) {
    EC_GROUP* group = Wallet::getDefaultEcGroup();
    EC_POINT* pubkeyPoint = ECCtools::vectorToEcPoint(group, pubKey);
    EC_KEY* ecKey = EC_KEY_new();
    EC_KEY_set_group(ecKey, group);
    EC_KEY_set_public_key(ecKey, pubkeyPoint);
    EVP_PKEY* pubkey = EVP_PKEY_new();
    EVP_PKEY_set1_EC_KEY(pubkey, ecKey);

    EC_GROUP_free(group);
    EC_POINT_free(pubkeyPoint);
    EC_KEY_free(ecKey);

    bool result = VerifySignature::verify(msg, signature, pubkey);
    EVP_PKEY_free(pubkey);

    return result;
}
