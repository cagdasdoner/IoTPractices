#include "MQTTClient.h"
#include "mqtt.h"
#include "network.h"
#include "global.h"
#include "credentials.h"

MQTTClient client;
volatile MQTTClient_deliveryToken deliveredtoken;

void delivered(void *context, MQTTClient_deliveryToken dt)
{
    printf("Message with token value %d delivery confirmed\n", dt);
    deliveredtoken = dt;
}

int msgarrvd(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    printf("Message arrived\n");
    printf("  topic: %s\n", topicName);
    printf("  message: ");

    char payloadToPost[message->payloadlen + 1];
    memset(payloadToPost, 0, message->payloadlen + 1);
    strncpy(payloadToPost, message->payload, message->payloadlen);

    printf("%s\n", payloadToPost);

    
    /* Do your implementation in here! */

    
    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);

    return 1;
}

void connlost(void *context, char *cause)
{
    printf("Connection lost due to : %s\n", cause);
}

void MQTTSubscribe(const char* topic)
{
    printf("Subscribing to topic %s\nfor client %s using QoS%d\n\n", 
        SENSOR_TOPIC, CLIENTID, QOS);
    MQTTClient_subscribe(client, topic, QOS);
}

void MQTTDisconnect(const char* topic)
{
    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
}

void MQTTBegin()
{
    int rc = -1;
    printf("Initializing MQTT...\n");
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_create(&client, BROKER_ADDR, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL);
    conn_opts.keepAliveInterval = KEEP_ALIVE;
    conn_opts.cleansession = 1;
    conn_opts.username = USERNAME;
    conn_opts.password = PASSWORD;

    MQTTClient_setCallbacks(client, NULL, connlost, msgarrvd, delivered);

    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(-1);       
    }
}

