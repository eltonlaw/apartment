#include <http.h>
#include <curl/curl.h>

HTTPResponse http_client(char** argv) {
    long flags = CURL_GLOBAL_ALL;
    curl_global_init(flags);
    HTTPResponse res;
    res.response_code = 200;
    curl_global_cleanup();
    return res;
}
