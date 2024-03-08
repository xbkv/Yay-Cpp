#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>

const std::string ID_CHECK_SECRET_KEY = "4aa6d1c301a97154bc1098c2";
const std::string API_KEY = "ccd59ee269c01511ba763467045c115779fcae3050238a252f1bd1a4b65cfec6";
const std::string SHARED_KEY = "yayZ1";
const std::string SHARED_STORE_KEY = "yayZ1payment";
const std::string API_VERSION_KEY = "e463476778d84e9ba594a5aaf391a516";
const std::string API_VERSION_NAME = "3.30";
const std::string VERSION_NAME = "3.30.0";

const std::string BASE_HOST = "api.yay.space";
const std::string BASE_API_URL = "https://" + BASE_HOST;
const std::string BASE_CASSANDRA_URL = "https://cas.yay.space/";
const std::string BASE_CONFIG_URL = "https://settings.yay.space/";
const std::string ID_CARD_CHECK_URL = "https://idcardcheck.com/";
const std::string WEB_SOCKET_URL = "wss://cable.yay.space/";

const struct {
    std::string deviceType;
    std::string osVersion;
    std::string screenDensity;
    std::string screenSize;
    std::string model;
} DEFAULT_DEVICE = {
    "android",
    "11",
    "3.5",
    "1440x2960",
    "Galaxy S9"
};

#endif