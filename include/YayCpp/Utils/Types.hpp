#include <string>
#include <map>
#include <cpprest/http_client.h>
#include <YayCpp/Utils/Logger.hpp>

struct RESTOptions {
    YCPLogger logger;
    std::string baseURL;
    std::map<std::string, std::string> proxy;
    int timeout;
    std::map<std::string, std::string> defaultHeaders;
};

struct RequestOptions {
    HttpMethod method;
    std::string route;
    bool requireAuth;
    std::map<std::string, web::json::value> params;
    std::map<std::string, web::json::value> json;
    std::string baseURL;
    std::string accessToken;
    std::map<std::string, std::string> headers;
};

struct ClientOptions {
    std::map<std::string, std::string> proxy;
    int timeout;
    int maxRetries;
    double backoffFactor;
    bool waitOnRateLimit;
    Cookie cookie;
    bool saveCookie;
    std::string cookiePassword;
    std::string cookieDirPath;
    std::string cookieFilename;
    std::vector<std::string> intents;
    bool debugMode;
    bool disableLog;

    ClientOptions() :
        timeout(30),
        maxRetries(3),
        backoffFactor(1.5),
        waitOnRateLimit(true),
        saveCookie(true),
        debugMode(false),
        disableLog(false) {}
};

struct CookieAuthentication {
    std::string accessToken;
    std::string refreshToken;
};

struct CookieUser {
    int userId;
    std::string email;
    std::string uuid;
};

struct CookieDevice {
    std::string deviceUuid;
};

struct Device {
    std::string deviceType;
    std::string osVersion;
    std::string screenDensity;
    std::string screenSize;
    std::string model;
};

typedef std::map<std::string, std::string> RequestObject;


struct LoginEmailUserRequest {
    std::string email;
    std::string password;
};

struct SearchCriteria {
    std::string nickname;
    std::string username;
    std::string biography;
    std::string prefecture;
    int gender;
};

struct ChannelCommand {
    std::string command;
    std::string identifier;
};

struct ChannelMessage {
    std::string identifier;
    EventMessage message;
    std::string type;
    std::string sid;
};

struct Identifier {
    std::string channel;
};

struct EventMessage {
    std::map<std::string, std::string> data;
    std::map<std::string, std::string> message;
    std::string event;
};

enum class HttpMethod {
    DELETE,
    GET,
    PATCH,
    POST,
    PUT
};

struct ErrorResponse {
    std::string result;
    std::string message;
    int errorCode;
    long long banUntil;
};

enum class GatewayIntents {
    ChatMessage,
    GroupUpdates
};

const std::map<std::string, std::string> GatewayIntentsMap = {
    {"ChatMessage", "ChatRoomChannel"},
    {"GroupUpdates", "GroupUpdatesChannel"}
};

const std::map<std::string, std::string> PostType = {
    {"text", "text"},
    {"media", "media"},
    {"image", "image"},
    {"video", "video"},
    {"survey", "survey"},
    {"call", "call"},
    {"shareableUrl", "shareable_url"}
};

const std::map<std::string, std::string> CallType = {
    {"voice", "voice"},
    {"video", "vdo"}
};

const std::map<std::string, std::string> ImageType = {
    {"post", "post"},
    {"chatMessage", "chat_message"},
    {"chatBackground", "chat_background"},
    {"report", "report"},
    {"userAvatar", "user_avatar"},
    {"userCover", "user_cover"},
    {"groupIcon", "group_icon"},
    {"groupCover", "group_cover"},
    {"groupThreadIcon", "group_thread_icon"}
};

// ShareableType定数の定義
const std::map<std::string, std::string> ShareableType = {
    {"group", "group"},
    {"thread", "thread"}
};