
#ifndef TX_CHAINPARAMS_H
#define TX_CHAINPARAMS_H

#include <utility>
#include <cstdint>
#include <vector>
#include <openssl/ossl_typ.h>
#include <openssl/ec.h>

#define VERSION "0.6.2"
#define VERSION_16BITS 62

#define CURRENCY_SWITZERLAND 1
#define CURRENCY_GERMANY 2
#define CURRENCY_AUSTRIA 3
#define CURRENCY_UNITED_KINGDOM 4
#define CURRENCY_IRELAND 5
#define CURRENCY_USA 6
#define CURRENCY_AUSTRALIA 7
#define CURRENCY_CHINA 8
#define CURRENCY_SWEDEN 9
#define CURRENCY_FRANCE 10
#define CURRENCY_CANADA 11
#define CURRENCY_JAPAN 12
#define CURRENCY_THAILAND 13
#define CURRENCY_NEW_ZEALAND 14
#define CURRENCY_UNITED_ARAB_EMIRATES 15
#define CURRENCY_FINLAND 16
#define CURRENCY_LUXEMBOURG 17
#define CURRENCY_SINGAPORE 18
#define CURRENCY_HUNGARY 19
#define CURRENCY_CZECH_REPUBLIC 20
#define CURRENCY_MALAYSIA 21
#define CURRENCY_UKRAINE 22
#define CURRENCY_ESTONIA 23
#define CURRENCY_MONACO 24
#define CURRENCY_LIECHTENSTEIN 25
#define CURRENCY_ICELAND 26
#define CURRENCY_HONG_KONG 27
#define CURRENCY_SPAIN 28
#define CURRENCY_RUSSIA 29
#define CURRENCY_ISRAEL 30
#define CURRENCY_PORTUGAL 31
#define CURRENCY_DENMARK 32
#define CURRENCY_TURKEY 33
#define CURRENCY_ROMANIA 34
#define CURRENCY_POLAND 35
#define CURRENCY_NETHERLANDS 36
#define CURRENCY_PHILIPPINES 37
#define CURRENCY_ITALY 38
#define CURRENCY_BRAZIL 39

#define CURRENCY_SWITZERLAND_EMISSION_RATE 19400000
#define CURRENCY_GERMANY_EMISSION_RATE 191400000
#define CURRENCY_AUSTRIA_EMISSION_RATE 20200000
#define CURRENCY_UNITED_KINGDOM_EMISSION_RATE 151900000
#define CURRENCY_IRELAND_EMISSION_RATE 11000000
#define CURRENCY_USA_EMISSION_RATE 747900000
#define CURRENCY_AUSTRALIA_EMISSION_RATE 55600000
#define CURRENCY_CHINA_EMISSION_RATE 3192100000
#define CURRENCY_SWEDEN_EMISSION_RATE 22900000
#define CURRENCY_FRANCE_EMISSION_RATE 155500000
#define CURRENCY_CANADA_EMISSION_RATE 84000000
#define CURRENCY_JAPAN_EMISSION_RATE 294000000
#define CURRENCY_THAILAND_EMISSION_RATE 155100000
#define CURRENCY_NEW_ZEALAND_EMISSION_RATE 10600000
#define CURRENCY_UNITED_ARAB_EMIRATES_EMISSION_RATE 21500000
#define CURRENCY_FINLAND_EMISSION_RATE 12700000
#define CURRENCY_LUXEMBOURG_EMISSION_RATE 1000000
#define CURRENCY_SINGAPORE_EMISSION_RATE 13000000
#define CURRENCY_HUNGARY_EMISSION_RATE 22700000
#define CURRENCY_CZECH_REPUBLIC_EMISSION_RATE 24500000
#define CURRENCY_MALAYSIA_EMISSION_RATE 73600000
#define CURRENCY_UKRAINE_EMISSION_RATE 104200000
#define CURRENCY_ESTONIA_EMISSION_RATE 3200000
#define CURRENCY_MONACO_EMISSION_RATE 100000
#define CURRENCY_LIECHTENSTEIN_EMISSION_RATE 100000
#define CURRENCY_ICELAND_EMISSION_RATE 800000
#define CURRENCY_HONG_KONG_EMISSION_RATE 17100000
#define CURRENCY_SPAIN_EMISSION_RATE 108000000
#define CURRENCY_RUSSIA_EMISSION_RATE 335240000
#define CURRENCY_ISRAEL_EMISSION_RATE 20610880
#define CURRENCY_PORTUGAL_EMISSION_RATE 23849600
#define CURRENCY_DENMARK_EMISSION_RATE 13469920
#define CURRENCY_TURKEY_EMISSION_RATE 190240000
#define CURRENCY_ROMANIA_EMISSION_RATE 45031200
#define CURRENCY_POLAND_EMISSION_RATE 88090400
#define CURRENCY_NETHERLANDS_EMISSION_RATE 40089600
#define CURRENCY_PHILIPPINES_EMISSION_RATE 243800000
#define CURRENCY_ITALY_EMISSION_RATE 138000000
#define CURRENCY_BRAZIL_EMISSION_RATE 481000000

#define CURRENCY_SWITZERLAND_DELEGATE_PAYOUT 1940000
#define CURRENCY_GERMANY_DELEGATE_PAYOUT  19140000
#define CURRENCY_AUSTRIA_DELEGATE_PAYOUT  2020000
#define CURRENCY_UNITED_KINGDOM_DELEGATE_PAYOUT  15190000
#define CURRENCY_IRELAND_DELEGATE_PAYOUT 1100000
#define CURRENCY_USA_DELEGATE_PAYOUT 74790000
#define CURRENCY_AUSTRALIA_DELEGATE_PAYOUT 5560000
#define CURRENCY_CHINA_DELEGATE_PAYOUT 319210000
#define CURRENCY_SWEDEN_DELEGATE_PAYOUT 2290000
#define CURRENCY_FRANCE_DELEGATE_PAYOUT 15550000
#define CURRENCY_CANADA_DELEGATE_PAYOUT 8400000
#define CURRENCY_JAPAN_DELEGATE_PAYOUT 29400000
#define CURRENCY_THAILAND_DELEGATE_PAYOUT 15510000
#define CURRENCY_NEW_ZEALAND_DELEGATE_PAYOUT 1060000
#define CURRENCY_UNITED_ARAB_EMIRATES_DELEGATE_PAYOUT 2150000
#define CURRENCY_FINLAND_DELEGATE_PAYOUT 1300000
#define CURRENCY_LUXEMBOURG_DELEGATE_PAYOUT 100000
#define CURRENCY_SINGAPORE_DELEGATE_PAYOUT 1300000
#define CURRENCY_HUNGARY_DELEGATE_PAYOUT 2270000
#define CURRENCY_CZECH_REPUBLIC_DELEGATE_PAYOUT 2450000
#define CURRENCY_MALAYSIA_DELEGATE_PAYOUT 7360000
#define CURRENCY_UKRAINE_DELEGATE_PAYOUT 10420000
#define CURRENCY_ESTONIA_DELEGATE_PAYOUT 320000
#define CURRENCY_MONACO_DELEGATE_PAYOUT 10000
#define CURRENCY_LIECHTENSTEIN_DELEGATE_PAYOUT 10000
#define CURRENCY_ICELAND_DELEGATE_PAYOUT 80000
#define CURRENCY_HONG_KONG_DELEGATE_PAYOUT 1710000
#define CURRENCY_SPAIN_DELEGATE_PAYOUT 10800000
#define CURRENCY_RUSSIA_DELEGATE_PAYOUT 33524000
#define CURRENCY_ISRAEL_DELEGATE_PAYOUT 2061088
#define CURRENCY_PORTUGAL_DELEGATE_PAYOUT 2384960
#define CURRENCY_DENMARK_DELEGATE_PAYOUT 1346992
#define CURRENCY_TURKEY_DELEGATE_PAYOUT 19024000
#define CURRENCY_ROMANIA_DELEGATE_PAYOUT 4503120
#define CURRENCY_POLAND_DELEGATE_PAYOUT 8809040
#define CURRENCY_NETHERLANDS_DELEGATE_PAYOUT 4008960
#define CURRENCY_PHILIPPINES_DELEGATE_PAYOUT 24380000
#define CURRENCY_ITALY_DELEGATE_PAYOUT 13800000
#define CURRENCY_BRAZIL_DELEGATE_PAYOUT 48100000

#define CURRENCY_SWITZERLAND_DEVELOPMENT_PAYOUT 1940000
#define CURRENCY_GERMANY_DEVELOPMENT_PAYOUT 19140000
#define CURRENCY_AUSTRIA_DEVELOPMENT_PAYOUT 2020000
#define CURRENCY_UNITED_KINGDOM_DEVELOPMENT_PAYOUT 15190000
#define CURRENCY_IRELAND_DEVELOPMENT_PAYOUT 1100000
#define CURRENCY_USA_DEVELOPMENT_PAYOUT 74790000
#define CURRENCY_AUSTRALIA_DEVELOPMENT_PAYOUT 5560000
#define CURRENCY_CHINA_DEVELOPMENT_PAYOUT 319210000
#define CURRENCY_SWEDEN_DEVELOPMENT_PAYOUT 2290000
#define CURRENCY_FRANCE_DEVELOPMENT_PAYOUT 15550000
#define CURRENCY_CANADA_DEVELOPMENT_PAYOUT 8400000
#define CURRENCY_JAPAN_DEVELOPMENT_PAYOUT 29400000
#define CURRENCY_THAILAND_DEVELOPMENT_PAYOUT 15510000
#define CURRENCY_NEW_ZEALAND_DEVELOPMENT_PAYOUT 1060000
#define CURRENCY_UNITED_ARAB_EMIRATES_DEVELOPMENT_PAYOUT 2150000
#define CURRENCY_FINLAND_DEVELOPMENT_PAYOUT 1300000
#define CURRENCY_LUXEMBOURG_DEVELOPMENT_PAYOUT 100000
#define CURRENCY_SINGAPORE_DEVELOPMENT_PAYOUT 1300000
#define CURRENCY_HUNGARY_DEVELOPMENT_PAYOUT 2270000
#define CURRENCY_CZECH_REPUBLIC_DEVELOPMENT_PAYOUT 2450000
#define CURRENCY_MALAYSIA_DEVELOPMENT_PAYOUT 7360000
#define CURRENCY_UKRAINE_DEVELOPMENT_PAYOUT 10420000
#define CURRENCY_ESTONIA_DEVELOPMENT_PAYOUT 320000
#define CURRENCY_MONACO_DEVELOPMENT_PAYOUT 10000
#define CURRENCY_LIECHTENSTEIN_DEVELOPMENT_PAYOUT 10000
#define CURRENCY_ICELAND_DEVELOPMENT_PAYOUT 80000
#define CURRENCY_HONG_KONG_DEVELOPMENT_PAYOUT 1710000
#define CURRENCY_SPAIN_DEVELOPMENT_PAYOUT 10800000
#define CURRENCY_RUSSIA_DEVELOPMENT_PAYOUT 33524000
#define CURRENCY_ISRAEL_DEVELOPMENT_PAYOUT 2061088
#define CURRENCY_PORTUGAL_DEVELOPMENT_PAYOUT 2384960
#define CURRENCY_DENMARK_DEVELOPMENT_PAYOUT 1346992
#define CURRENCY_TURKEY_DEVELOPMENT_PAYOUT 19024000
#define CURRENCY_ROMANIA_DEVELOPMENT_PAYOUT 4503120
#define CURRENCY_POLAND_DEVELOPMENT_PAYOUT 8809040
#define CURRENCY_NETHERLANDS_DEVELOPMENT_PAYOUT 4008960
#define CURRENCY_PHILIPPINES_DEVELOPMENT_PAYOUT  24380000
#define CURRENCY_ITALY_DEVELOPMENT_PAYOUT  13800000
#define CURRENCY_BRAZIL_DEVELOPMENT_PAYOUT  48100000

// Upgrades
#define UPGRADE_0_2_0_BLOCK_HEIGHT 85000 // block height
#define ICELAND_ACTIVATION_BLOCK_HEIGHT 150000
#define HONG_KONG_ACTIVATION_BLOCK_HEIGHT 222000
#define SPAIN_ACTIVATION_BLOCK_HEIGHT 222000
#define NEW_COUNTRIES_BATCH_0_ACTIVATION_BLOCK_HEIGHT 279000
#define NEW_COUNTRIES_BATCH_1_ACTIVATION_BLOCK_HEIGHT 292000
#define ENFORCE_PKH_LENGTH_BLOCK_HEIGHT 279000

#define LATEST_BLOCK_VERSION 2
#define HALVING_INTERVAL_IN_BLOCKS (60*24*365)
#define NUMBER_OF_HALVINGS 4

#define DEV_FUND_PUBLIC_KEY "034603bf48fdccc8e405e270aa0c222a250dcabeb6246d1439d26c54f746274bca"
#define UBIC_ROOT_PRIVATE_KEY "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX"

#define PAYLOAD_TYPE_DSC_CERTIFICATE 1
#define MAXIMUM_TRANSACTION_PAYLOAD_SIZE 4000

#define SCRIPT_EMPTY 0x00
#define SCRIPT_LINK 0x01
#define SCRIPT_PKH 0x02
#define SCRIPT_ADD_CERTIFICATE 0x03
#define SCRIPT_DEACTIVATE_CERTIFICATE 0x04
#define SCRIPT_VOTE 0x05
#define SCRIPT_REGISTER_PASSPORT 0x09

#define PKH_SECP256K1_VERSION 0x00

#define NET_MAIN 0x01
#define NET_TEST 0x02
#define NET_CURRENT 0x01

#define DB_ADDRESS_STORE 0
#define DB_BLOCK_INDEX 1
#define DB_NTPSK_ALREADY_USED 2
#define DB_DSC_ATTACHED_PASSPORTS_COUNTER 3
#define DB_BLOCK_HEADERS 4
#define DB_MY_TRANSACTIONS 5
#define DB_VOTES 6

#define BLOCK_FILES_MAX_SIZE (1800 * 1000 * 1000) /* in bytes */
#define LOG_MAX_SIZE (100 * 1000 * 1000) /* in bytes */
#define MAX_NETWORK_MESSAGE_SIZE 2000000

#define SERIALIZATION_VERSION 1
#define BLOCK_SIZE_MAX 1900000
#define BLOCK_INTERVAL_IN_SECONDS 60

#define SEED_SIZE_MAX 4096
#define CERT_SIZE_MAX 4096

#define TRANSACTION_SIZE_MAX 20000

#define BROADCAST_TRANSACTION true
#define NO_BROADCAST_TRANSACTION false

//#define CSCA_MATURATION_TIME_IN_BLOCKS (60*24*14)
#define CSCA_MATURATION_TIME_IN_BLOCKS 0
#define CSCA_MATURATION_SUSPENSIONTIME_IN_BLOCKS 100 /* during the first 100 blocks maturation is ignored */
#define TXFEE_FACTOR 0.25

#define VOTES_INTERVAL 0
#define MAXIMUM_DELEGATE_COUNT 51
#define MINIMUM_DELEGATE_VOTES 7

#define MAXIMUM_PASSPORTS_PER_ADDRESS 1
#define MAXIMUM_PASSPORTS_PER_ADDRESS_ACTIVATION_HEIGHT 289870

#if defined(__APPLE__)
    #ifdef TEST_MODE
        #define BASE_PATH "/Applications/UBIC-test/"
    #else
        #define BASE_PATH "/Applications/UBIC/"
    #endif
    #define BASE_WEB_PATH "/Applications/UBIC/web/"
    #define CONFIG_BASE_PATH "ubic/"
    #define CONFIG_PATH "config.ini"
#endif
#if defined(__linux__)
    #ifdef TEST_MODE
        #define BASE_PATH "/var/ubic-test/"
    #else
        #define BASE_PATH "/var/ubic/"
    #endif
    #define BASE_WEB_PATH "/var/ubic/web/"
    #define CONFIG_BASE_PATH "ubic/"
    #define CONFIG_PATH "config.ini"
#endif

#if defined(_WIN32)
    #define BASE_PATH "./"
    #define BASE_WEB_PATH "./web"
    #define CONFIG_BASE_PATH "ubic/"
    #define CONFIG_PATH "config.ini"
#endif

#define MAX_NUMBER_OF_MY_TRANSACTIONS_TO_DISPLAY 1000

#ifdef TEST_MODE
    #define NET_PORT "1335"
    #define NET_PORT_INT 1335
#else
    #define NET_PORT "1334"
    #define NET_PORT_INT 1334
#endif

#define NET_API_PORT 12303
#define NET_WEB_PORT 6789

#endif //TX_CHAINPARAMS_H
