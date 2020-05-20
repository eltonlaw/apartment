struct HTTPResponse {
    int response_code;
};
typedef struct HTTPResponse HTTPResponse;
HTTPResponse http_client(char**);
