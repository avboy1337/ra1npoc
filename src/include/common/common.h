#ifndef COMMON_H
#define COMMON_H

#define DFU_UNKOWN_TYPE (0)
#define DFU_LEGACY      (1 << 1)
#define DFU_IPHONE7     (1 << 2)
#define DFU_IPHONEX     (1 << 3)

int enter_dfu_via_recovery(io_client_t client);
int payload_stage2(io_client_t client, checkra1n_payload_t payload);
int pongo(io_client_t client, checkra1n_payload_t payload);
int connect_to_stage2(io_client_t client, checkra1n_payload_t payload);

transfer_t usb_req_stall(io_client_t client);
transfer_t usb_req_leak(io_client_t client, unsigned char* blank);
transfer_t usb_req_no_leak(io_client_t client, unsigned char* blank);
transfer_t leak(io_client_t client, unsigned char* blank);
transfer_t no_leak(io_client_t client, unsigned char* blank);
transfer_t send_data(io_client_t client, unsigned char* buf, size_t size);
transfer_t send_data_with_time(io_client_t client, unsigned char* buf, size_t size, int timeout);
transfer_t get_status(io_client_t client, unsigned char* buf, size_t size);
transfer_t send_abort(io_client_t client);

transfer_t usb_req_leak_with_async(io_client_t client,
                                   unsigned char* blank,
                                   int usleep_time,
                                   async_transfer_t transfer);

#endif
