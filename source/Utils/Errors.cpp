#include "YayCpp/Utils/Errors.hpp"

YCPError::YCPError(const std::string& message) : std::runtime_error(message) {}

HTTPError::HTTPError(const ErrorResponse& response) : YCPError(response.message), response(response) {}

const ErrorResponse& HTTPError::getResponse() const {
    return response;
}

BadRequestError::BadRequestError(const ErrorResponse& response) : HTTPError(response) {}

AuthenticationError::AuthenticationError(const ErrorResponse& response) : HTTPError(response) {}

ForbiddenError::ForbiddenError(const ErrorResponse& response) : HTTPError(response) {}

NotFoundError::NotFoundError(const ErrorResponse& response) : HTTPError(response) {}

RateLimitError::RateLimitError(const ErrorResponse& response) : HTTPError(response) {}

ServerError::ServerError(const ErrorResponse& response) : HTTPError(response) {}