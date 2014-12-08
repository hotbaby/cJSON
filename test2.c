/*************************************************************************
> File Name: test2.c
> Author: yy
> Mail: mengyy_linux@163.com
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"

int main(int argc, char *argcgv[])
{
    int         ret;
    cJSON       *json;
    cJSON       *type;
    const char  *text = "{\"type\":\"router\",\"method\":\"WIFI.getStationList\",\"token\":\"c64302caa6b5416d9ee7ef485c55f48a\", \"params\":[\"2G\"]}";
    const char  *out = NULL;

    json=cJSON_Parse(text);
    if (!json)
    {
        fprintf(stderr, "Error before: [%s]\n",cJSON_GetErrorPtr());
    }
    else
    {
        type = cJSON_GetObjectItem(json, "type");
        if (!type)
        {
            fprintf(stderr, "Error before: [%s]\n",cJSON_GetErrorPtr());
        }
        else
        {
            out = cJSON_Print(type);
            fprintf(stderr, "%s\n", out);

            if (!(ret = strncmp(out+1, "router", strlen("router")-1)))
            {
                fprintf(stderr, "true.\n");
            }
            else
            {
                fprintf(stderr, "false.\n");
            }
            free((void*)out);
            out = NULL;
        }

        out=cJSON_Print(json);
        fprintf(stderr, "%s\n",out);
        free((void*)out);
        out = NULL;
    }
    cJSON_Delete(json);

    return 0;
}
