#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define MAX 100

 typedef struct{
   int top;
   char item[MAX];
 
 }stack;
   
   
   void init(stack*s){
     s-> top=-1;
     
   }
   
   int isempty(stack*s){
     return s-> top ==-1;
    
   }
   int  isfull(stack*s){
     return s-> top ==MAX-1;
   }
   
   void push(stack*s , char item){
     if(isfull(s)){
       printf("stack overflow!");
       return;
     }
     s-> item[++(s->top)] = item;
   }
    
    char pop(stack*s){
      if(isempty(s)){
        printf("stack underflow !");
        return-1;
        
      }
      return s->item[(s->top)--];
    }
    
    char peek(stack*s){
      if(isempty(s)){
        return-1;
      }
      return s-> item[s->top];
    }
    
    int precedence(char ch){
      switch(ch){
    case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
      }
    }
    
    int isoperator(char ch){
      return ch =='+'||ch =='-'|| ch == '*' || ch =='/'|| ch == '^';
    }
    void infixtopostfix(char infix[], char postfix[]){
      stack s;
      init(&s);
      
      int i,j=0;
      for(i=0 ; infix[i]!= '\0'; i++){
        char ch = infix[i];
        
        
        if(isalnum(ch)){
          postfix[j++] = ch;
          
        }
        else if(ch =='('){
          push(&s,ch);
        }
        else if(ch ==')'){
          while(!isempty(&s)&&peek(&s)!= '('){
            postfix[j++] = pop(&s);
            
            
          }
      
          pop(&s);
          
        }
        else if(isoperator(ch)){
          while(!isempty(&s)&& precedence(peek(&s))>= precedence(ch)){
            postfix[j++]= pop(&s);
            
          }
          push(&s, ch);
        }
        while(!isempty(&s)){
          postfix[j++] = pop(&s);
          postfix[j] = '\0';
          
        }
      }
      
    }
int main()
{char infix[MAX],postfix[MAX];

printf("enter a infix expression:");
scanf("%s", infix);

infixtopostfix(infix,postfix);

printf("postfix expression: %s\n", postfix);

return 0;
}