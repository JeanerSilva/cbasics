#include<stdio.h>

//modo errado
void notification_callbackErrado(struct my_context *context, int notification_flag) {
  context->foo++;
}



struct my_context {
  int foo;
};

void notification_callback(void *context, int notification_flag) {
  struct my_context *mycontext = (struct my_context *)context;
  mycontext->foo++;
}

typedef void (*callback_type)(void *context, int notification_flag, bool *should_continue);

int main () {

    //errado
    register_notification((callback_type)notification_callback, &a_context);

    //meio
    register_notification((callback_type)printf, &a_context);
    

    //certo
    register_notification(notification_callback, &a_context);
    return 0;
}