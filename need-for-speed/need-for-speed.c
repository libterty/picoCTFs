#include "need-for-speed.h"



int _init(EVP_PKEY_CTX *ctx)

{
  int iVar1;
  
  iVar1 = __gmon_start__();
  return iVar1;
}



void null_pointer(void)

{
                    // WARNING: Treating indirect jump as call
  (*(code *)(undefined *)0x0)();
  return;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int putchar(int __c)

{
  int iVar1;
  
  iVar1 = putchar(__c);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

int puts(char *__s)

{
  int iVar1;
  
  iVar1 = puts(__s);
  return iVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

uint alarm(uint __seconds)

{
  uint uVar1;
  
  uVar1 = alarm(__seconds);
  return uVar1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

__sighandler_t __sysv_signal(int __sig,__sighandler_t __handler)

{
  __sighandler_t p_Var1;
  
  p_Var1 = __sysv_signal(__sig,__handler);
  return p_Var1;
}



// WARNING: Unknown calling convention yet parameter storage is locked

void exit(int __status)

{
                    // WARNING: Subroutine does not return
  exit(__status);
}



void __cxa_finalize(void)

{
  __cxa_finalize();
  return;
}



void _start(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  undefined8 in_stack_00000000;
  undefined auStack8 [8];
  
  __libc_start_main(main,in_stack_00000000,&stack0x00000008,__libc_csu_init,__libc_csu_fini,param_3,
                    auStack8);
  do {
                    // WARNING: Do nothing block with infinite loop
  } while( true );
}



// WARNING: Removing unreachable block (ram,0x001006a7)
// WARNING: Removing unreachable block (ram,0x001006b3)

void deregister_tm_clones(void)

{
  return;
}



// WARNING: Removing unreachable block (ram,0x001006f8)
// WARNING: Removing unreachable block (ram,0x00100704)

void register_tm_clones(void)

{
  return;
}



void __do_global_dtors_aux(void)

{
  if (completed_7698 != '\0') {
    return;
  }
  __cxa_finalize(__dso_handle);
  deregister_tm_clones();
  completed_7698 = 1;
  return;
}



void frame_dummy(void)

{
  register_tm_clones();
  return;
}



void decrypt_flag(int key)

{
  int l_key;
  uint i;
  
  l_key = key;
  i = 0;
  while (i < 0x37) {
    flag[(int)i] = flag[(int)i] ^
                   *(byte *)((long)&l_key +
                            (long)(int)((i - ((int)i >> 0x1f) & 1) + ((int)i >> 0x1f)));
    if ((int)i % 3 == 2) {
      l_key = l_key + 1;
    }
    i = i + 1;
  }
  return;
}



undefined4 calculate_key(void)

{
  int t_key;
  
  t_key = -0x319e0722;
  do {
    t_key = t_key + -1;
  } while (t_key != -0x18cf0391);
  return 0xe730fc6f;
}



void alarm_handler(void)

{
  puts("Not fast enough. BOOM!");
                    // WARNING: Subroutine does not return
  exit(0);
}



void set_timer(void)

{
  __sighandler_t ss;
  
  ss = __sysv_signal(0xe,alarm_handler);
  if (ss == (__sighandler_t)0xffffffffffffffff) {
    puts("\n\nSomething bad happened here. ");
                    // WARNING: Subroutine does not return
    exit(0);
  }
  alarm(1);
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void get_key(void)

{
  puts("Creating key...");
  _key = calculate_key();
  puts("Finished");
  return;
}



// WARNING: Globals starting with '_' overlap smaller symbols at the same address

void print_flag(void)

{
  puts("Printing flag:");
  decrypt_flag(_key);
  puts(flag);
  return;
}



// increase speed // 

void header(void)

{
  uint m_speed;
  
  puts("Keep this thing over 50 mph!");
  m_speed = 0;
  // looping when speed not reach 28 ?? //
  while (m_speed < 0x1c) {
    // print char 61 ? //
    putchar(0x3d);
    m_speed = m_speed + 1;
  }
  puts("\n");
  return;
}



undefined8 main(void)

{
  header();
  set_timer();
  get_key();
  print_flag();
  return 0;
}



void __libc_csu_init(EVP_PKEY_CTX *param_1,undefined8 param_2,undefined8 param_3)

{
  long lVar1;
  
  _init(param_1);
  lVar1 = 0;
  do {
    (*(code *)(&__frame_dummy_init_array_entry)[lVar1])((ulong)param_1 & 0xffffffff,param_2,param_3)
    ;
    lVar1 = lVar1 + 1;
  } while (lVar1 != 1);
  return;
}



void __libc_csu_fini(void)

{
  return;
}



void _fini(void)

{
  return;
}


