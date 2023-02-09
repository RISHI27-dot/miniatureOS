enter_kernel:
	[extern kernel_main] ; the main function kn that will be entry point of kernel.
	call kernel_main ; Call the main functionj
    jmp $ ; loop infinately if kernel ever returns.
