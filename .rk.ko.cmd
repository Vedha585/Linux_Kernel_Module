cmd_/home/remnux/Desktop/rootkit/rk.ko := ld -r -m elf_x86_64  -z max-page-size=0x200000  --build-id  -T ./scripts/module-common.lds -o /home/remnux/Desktop/rootkit/rk.ko /home/remnux/Desktop/rootkit/rk.o /home/remnux/Desktop/rootkit/rk.mod.o;  true