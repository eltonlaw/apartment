#include <stdio.h>
#include <stdlib.h>
#include <pcap.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

char* address_text(in_addr_t p) {
    struct in_addr addr;
    addr.s_addr = p;
    char* a = inet_ntoa(addr);
    if(a == NULL) {
        perror("inet_ntoa");
        exit(1);
    }
    return a;
}

/* Prints network address and mask of all capture devices */
void scan_devices(void) {
    int ret;
    char errbuf[PCAP_ERRBUF_SIZE];

    /* Get all valid devices */
    pcap_if_t *alldevs;
    ret = pcap_findalldevs(&alldevs, errbuf);
    if(ret == -1) {
        printf("Error encountered looking up device.\n%s\n",errbuf);
        exit(1);
    }
    if(alldevs == NULL) {
        printf("No devices found");
        exit(0);
    }

    bpf_u_int32 netp;  // ip
    bpf_u_int32 maskp; // subnet mask
    char* net;
    char* mask;
    char *dev_name;
    pcap_if_t *dev;

    dev = alldevs;
    while (1) {
        dev_name = dev->name;
        printf("DEV: %s\n",dev_name);
        /*  network address and mask of the device */
        ret = pcap_lookupnet(dev_name,&netp,&maskp,errbuf);
        if(ret == -1) {
            printf("%s\n",errbuf);
            exit(1);
        }
        net = address_text(netp);
        printf("NET: %s\n", net);
        mask = address_text(maskp);
        printf("MASK: %s\n",mask);

        dev = dev->next;
        if (dev == NULL) {
            break;
        }
    }
    pcap_freealldevs(alldevs);
}
