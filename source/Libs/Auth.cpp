#include <include/YayCpp/Libs/Auth.hpp>

AuthAPI::AuthAPI(BaseClient& base) : base(base) {}

pplx::task<web::json::value> AuthAPI::changeEmail(const std::string& email, const std::string& password, const std::string& emailGrantToken = "") {
    web::uri_builder uriBuilder(U(BASE_API_URL + "/v1/users/change_email"));

    uriBuilder.append_query(U("api_key"), U(API_KEY));
    uriBuilder.append_query(U("email"), web::uri::encode_data_string(email));
    uriBuilder.append_query(U("password"), web::uri::encode_data_string(password));
    uriBuilder.append_query(U("email_grant_token"), web::uri::encode_data_string(emailGrantToken));

    web::http::client::http_client_config clientConfig;

    web::http::client::http_client client(BASE_API_URL, clientConfig);

    web::http::http_request request(web::http::methods::PUT);
    request.set_request_uri(uriBuilder.to_uri());

    return client.request(request).then([](web::http::http_response response) {
        if (response.status_code() == web::http::status_codes::OK) {
            return response.extract_json();
        } else {
            throw std::runtime_error("HTTP request failed with status code: " + std::to_string(response.status_code()));
        }
    });
}

pplx::task<TokenResponse> AuthAPI::getToken(const std::string& grantType, const std::string& email, const std::string& password, const std::string& refreshToken) {
    web::uri_builder uriBuilder(U(BASE_API_URL + "/api/v1/oauth/token"));

    uriBuilder.append_query(U("grant_type"), grantType);
    uriBuilder.append_query(U("email"), email);
    uriBuilder.append_query(U("password"), password);
    uriBuilder.append_query(U("refresh_token"), refreshToken);

    web::http::client::http_client_config clientConfig;

    web::http::client::http_client client(BASE_API_URL, clientConfig);

    web::http::http_request request(web::http::methods::POST);
    request.set_request_uri(uriBuilder.to_uri());

    return client.request(request).then([](web::http::http_response response) {
        if (response.status_code() == web::http::status_codes::OK) {
            return response.extract_json();
        } else {
            throw std::runtime_error("HTTP request failed with status code: " + std::to_string(response.status_code()));
        }
    }).then([](web::json::value jsonValue) {

        TokenResponse tokenResponse;

        return tokenResponse;
    });
}

pplx::task<LoginUserResponse> AuthAPI::loginWithEmail(const LoginEmailUserRequest& requests) {
    web::uri_builder uriBuilder(U(BASE_API_URL + "/v3/users/login_with_email"));

    web::http::client::http_client_config clientConfig;
    web::http::client::http_client client(BASE_API_URL, clientConfig);

    web::http::http_request request(web::http::methods::POST);
    request.set_request_uri(uriBuilder.to_uri());
    request.headers().set_content_type(U("application/json"));

    web::json::value requestBody;
    requestBody[U("api_key")] = web::json::value::string(API_KEY);
    requestBody[U("email")] = web::json::value::string(requests.email);
    requestBody[U("password")] = web::json::value::string(requests.password);
    requestBody[U("uuid")] = web::json::value::string(this->uuid());

    request.set_body(requestBody);

    return client.request(request).then([](web::http::http_response response) {
        if (response.status_code() == web::http::status_codes::OK) {
            return response.extract_json();
        } else {
            throw std::runtime_error("HTTP request failed with status code: " + std::to_string(response.status_code()));
        }
    }).then([](web::json::value jsonResponse) {
        LoginUserResponse loginUserResponse;
        return loginUserResponse;
    });
}

pplx::task<void> AuthAPI::logoutFromDevice() {
    web::uri_builder uriBuilder(U(BASE_API_URL + "/v1/users/logout"));

    web::http::client::http_client_config clientConfig;
    web::http::client::http_client client(BASE_API_URL, clientConfig);

    web::http::http_request request(web::http::methods::POST);
    request.set_request_uri(uriBuilder.to_uri());
    request.headers().set_content_type(U("application/json"));

    web::json::value requestBody;
    requestBody[U("uuid")] = web::json::value::string(this->uuid());

    request.set_body(requestBody);

    return client.request(request).then([](web::http::http_response response) {
        if (response.status_code() != web::http::status_codes::OK) {
            throw std::runtime_error("HTTP request failed with status code: " + std::to_string(response.status_code()));
        }
    });
}

pplx::task<void> AuthAPI::migrateToken(const std::string& token) {
    web::uri_builder uriBuilder(U(BASE_API_URL + "/api/v1/oauth/token/migrate"));

    web::http::client::http_client_config clientConfig;
    web::http::client::http_client client(BASE_API_URL, clientConfig);

    web::http::http_request request(web::http::methods::POST);
    request.set_request_uri(uriBuilder.to_uri());
    request.headers().set_content_type(U("application/json"));

    web::json::value requestBody;
    requestBody[U("token")] = web::json::value::string(token);

    request.set_body(requestBody);

    return client.request(request).then([](web::http::http_response response) {
        if (response.status_code() != web::http::status_codes::OK) {
            throw std::runtime_error("HTTP request failed with status code: " + std::to_string(response.status_code()));
        }
    });
}

pplx::task<void> AuthAPI::registerDeviceToken(const std::string& deviceToken, const std::string& deviceType, const std::string& osVersion, const std::string& screenResolution, const std::string& screenDensity, const std::string& deviceModel, const std::string& appsflyerId, const std::string& advertisingId) {
    web::uri_builder uriBuilder(U(BASE_API_URL + "/v2/users/device_tokens/new"));

    web::http::client::http_client_config clientConfig;
    web::http::client::http_client client(BASE_API_URL, clientConfig);

    web::http::http_request request(web::http::methods::POST);
    request.set_request_uri(uriBuilder.to_uri());
    request.headers().set_content_type(U("application/json"));

    web::json::value requestBody;
    requestBody[U("device_token")] = web::json::value::string(deviceToken);
    requestBody[U("device_type")] = web::json::value::string(deviceType);
    requestBody[U("os_version")] = web::json::value::string(osVersion);
    requestBody[U("screen_resolution")] = web::json::value::string(screenResolution);
    requestBody[U("screen_density")] = web::json::value::string(screenDensity);
    requestBody[U("device_model")] = web::json::value::string(deviceModel);
    requestBody[U("appsflyer_id")] = web::json::value::string(appsflyerId);
    requestBody[U("advertising_id")] = web::json::value::string(advertisingId);

    request.set_body(requestBody);

    return client.request(request).then([](web::http::http_response response) {
        if (response.status_code() != web::http::status_codes::OK) {
            throw std::runtime_error("HTTP request failed with status code: " + std::to_string(response.status_code()));
        }
    });
}

pplx::task<void> AuthAPI::resendConfirmEmail() {
    web::uri_builder uriBuilder(U(BASE_API_URL + "/v2/users/resend_confirm_email"));

    web::http::client::http_client_config clientConfig;
    web::http::client::http_client client(BASE_API_URL, clientConfig);

    web::http::http_request request(web::http::methods::POST);
    request.set_request_uri(uriBuilder.to_uri());
    request.headers().set_content_type(U("application/json"));

    return client.request(request).then([](web::http::http_response response) {
        if (response.status_code() != web::http::status_codes::OK) {
            throw std::runtime_error("HTTP request failed with status code: " + std::to_string(response.status_code()));
        }
    });
}

pplx::task<void> AuthAPI::restoreUser(int userId) {
    web::uri_builder uriBuilder(U(BASE_API_URL + "/v2/users/restore"));

    web::http::client::http_client_config clientConfig;
    web::http::client::http_client client(BASE_API_URL, clientConfig);

    web::http::http_request request(web::http::methods::POST);
    request.set_request_uri(uriBuilder.to_uri());
    request.headers().set_content_type(U("application/json"));

    web::json::value requestBody;
    requestBody[U("user_id")] = web::json::value::number(userId);

    request.set_body(requestBody);

    return client.request(request).then([](web::http::http_response response) {
        if (response.status_code() != web::http::status_codes::OK) {
            throw std::runtime_error("HTTP request failed with status code: " + std::to_string(response.status_code()));
        }
    });
}

pplx::task<void> AuthAPI::revokeTokens() {
    web::uri_builder uriBuilder(U(BASE_API_URL + "/v1/users/device_tokens"));

    web::http::client::http_client_config clientConfig;
    web::http::client::http_client client(BASE_API_URL, clientConfig);

    web::http::http_request request(web::http::methods::DEL);
    request.set_request_uri(uriBuilder.to_uri());
    request.headers().set_content_type(U("application/json"));


    return client.request(request).then([](web::http::http_response response) {
        if (response.status_code() != web::http::status_codes::OK) {
            throw std::runtime_error("HTTP request failed with status code: " + std::to_string(response.status_code()));
        }
    });
}

pplx::task<LoginUpdateResponse> AuthAPI::saveAccountWithEmail(const std::string& email, const std::string& password, const std::string& currentPassword, const std::string& emailGrantToken) {
    web::uri_builder uriBuilder(U(BASE_API_URL + "/v3/users/login_update"));

    web::http::client::http_client_config clientConfig;
    web::http::client::http_client client(BASE_API_URL, clientConfig);

    web::http::http_request request(web::http::methods::POST);
    request.set_request_uri(uriBuilder.to_uri());
    request.headers().set_content_type(U("application/json"));


    web::json::value requestBody;
    requestBody[U("api_key")] = web::json::value::string(API_KEY);
    requestBody[U("email")] = web::json::value::string(email);
    requestBody[U("password")] = web::json::value::string(password);
    requestBody[U("current_password")] = web::json::value::string(currentPassword);
    requestBody[U("email_grant_token")] = web::json::value::string(emailGrantToken);

    request.set_body(requestBody);

    return client.request(request).then([](web::http::http_response response) {
        if (response.status_code() != web::http::status_codes::OK) {
            throw std::runtime_error("HTTP request failed with status code: " + std::to_string(response.status_code()));
        } else {
            return response.extract_json().then([](web::json::value jsonValue) {
                LoginUpdateResponse loginUpdateResponse;

                return loginUpdateResponse;
            });
        }
    });
}

std::string AuthAPI::uuid() const {
    return this->base.uuid();
}

std::string AuthAPI::deviceUuid() const {
    return this->base.deviceUuid();
}

std::string AuthAPI::signedInfo() const {
    std::string deviceUuid = this->deviceUuid();
    auto now = std::chrono::system_clock::now();
    auto timestamp = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
    bool requireSharedKey = false;
    return md5(deviceUuid, timestamp, requireSharedKey);
}
