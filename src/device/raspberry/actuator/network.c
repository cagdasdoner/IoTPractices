#include <curl/curl.h>
#include "global.h"
#include "credentials.h"

void HTTPPostCloud(char* data)
{
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if(curl)
    {
        char postURL[MAX_URL_LEN];
        memset(postURL, 0, MAX_URL_LEN);
        sprintf(postURL, "%s/update?api_key=%s&field1=%s", THINGSPEAK_API, THINGSPEAK_KEY, data);
        curl_easy_setopt(curl, CURLOPT_URL, postURL);
        res = curl_easy_perform(curl);

        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
        }
        else
        {
            printf(" HTTP GET succeeded.\n");
        }
        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();
}

void NETBegin()
{

}
