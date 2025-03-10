#ifndef _NIM_CLIENT_UNITEST_H
#define _NIM_CLIENT_UNITEST_H

#include "fcx.h"
#include "gtest/gtest.h"

void test_nim_client_init_func(fcx_bool_t isTest);
void test_nim_client_cleanup_func();
void test_nim_client_login_func(fcx_bool_t isTest, const char* account, const char* password);
void test_nim_client_logout_func();

#define PRETEST_LOGIN_REQUIRED(using_test_server, account, password) \
    test_nim_client_init_func(using_test_server);                    \
    test_nim_client_login_func(using_test_server, (account), (password))

#define POSTTEST_LOGOUT_AND_CLEANUP() \
    test_nim_client_logout_func();    \
    test_nim_client_cleanup_func()

class NIMTestBase : public testing::Test {
public:
    NIMTestBase() {}
    virtual ~NIMTestBase() {}

    static void SetUpTestCase() {
        PrepareTestCase();
        PRETEST_LOGIN_REQUIRED(UseTestServer ? fcx_true : fcx_false, LoginAccount.c_str(), Password.c_str());
    }
    static void TearDownTestCase() { POSTTEST_LOGOUT_AND_CLEANUP(); }

    static std::string LoginAccount;
    static std::string Password;
    static bool UseTestServer;

protected:
    static void PrepareTestCase(){};
};

#endif  // !_NIM_CLIENT_UNITEST_H
