#ifndef YJS_ERROR_HPP
#define YJS_ERROR_HPP

#include <stdexcept>
#include <YayCpp/Utils/Types.hpp>
#include <YayCpp/Utils/Response.hpp>

class YCPError : public std::runtime_error {
public:
    explicit YCPError(const std::string& message);

};

class HTTPError : public YCPError {
public:
    explicit HTTPError(const ErrorResponse& response);

    const ErrorResponse& getResponse() const;

private:
    ErrorResponse response;
};

class BadRequestError : public HTTPError {
public:
    explicit BadRequestError(const ErrorResponse& response);

};

class AuthenticationError : public HTTPError {
public:
    explicit AuthenticationError(const ErrorResponse& response);

};

class ForbiddenError : public HTTPError {
public:
    explicit ForbiddenError(const ErrorResponse& response);

};

class NotFoundError : public HTTPError {
public:
    explicit NotFoundError(const ErrorResponse& response);

};

class RateLimitError : public HTTPError {
public:
    explicit RateLimitError(const ErrorResponse& response);

};

class ServerError : public HTTPError {
public:
    explicit ServerError(const ErrorResponse& response);

};

#endif