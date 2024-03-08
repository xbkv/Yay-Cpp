#ifndef AUTH_H
#define AUTH_H

#include <string>
#include <iostream>
#include <future>
#include <cpprest/http_client.h>
#include <YayCpp/Utils/Response.hpp>
#include <YayCpp/Utils/Constants.hpp>
#include <YayCpp/Utils/Types.hpp>

class AuthAPI {
public:
 
    AuthAPI(BaseClient& base);

    pplx::task<web::json::value> changeEmail(const std::string& email, const std::string& password, const std::string& emailGrantToken = "");

    pplx::task<web::json::value> changePassword(const std::string& currentPassword, const std::string& newPassword);

    pplx::task<TokenResponse> getToken(const std::string& grantType, const std::string& email = "", const std::string& password = "", const std::string& refreshToken = "");

    pplx::task<LoginUserResponse> loginWithEmail(const LoginEmailUserRequest& request);

    pplx::task<void> logoutFromDevice();

    pplx::task<void> migrateToken(const std::string& token);

    pplx::task<void> registerDeviceToken(const std::string& deviceToken, const std::string& deviceType, const std::string& osVersion, const std::string& screenResolution, const std::string& screenDensity, const std::string& deviceModel, const std::string& appsflyerId, const std::string& advertisingId = "");

    pplx::task<void> resendConfirmEmail();

    pplx::task<void> restoreUser(int userId);

    pplx::task<void> revokeTokens();

    pplx::task<LoginUpdateResponse> saveAccountWithEmail(const std::string& email, const std::string& password = "", const std::string& currentPassword = "", const std::string& emailGrantToken = "");

private:

    BaseClient& base;

    std::string uuid() const;

    std::string deviceUuid() const;

    std::string signedInfo() const;
};

#endif
