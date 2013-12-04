/***********************************************
|@author Matt Scaperoth
|@hash.h contains all functions for project 2
|@project Project 3.1
|@purpose: To successfully handle parsing a program
|     into a hash table where logic can be 
|     completed on the values when they appear
|     in the program.
|
|@assumptions and decisions: 
|   expressions between reals and ints are allowed
|   but the parser still returns a print statement
|   saying that they are different as a warning 
|   instead of an error.
|
|   instead of returning a type, the function
|   to check if symbol exists in hash returns
|   the symbol itself.
| 
|   only one struct is needed.
|
************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHLENGTH  50
#define PRINT_ERRORS 0 /*turn this to 1 to show all output for EXTREME debugging. 0 to disable.*/

FILE *out;

/**
 * single node in linked list of symbols as symbol table
 */
typedef struct symbol_node symbol_t;
typedef struct symbol_node* single_symbol;

struct symbol_node
{
  char *name; /* name of symbol */
  char type; /* symbol type: int, real... */
  int scope; /*scope of the variable*/
  single_symbol next; /* link field */
};

int NUM_ERRORS = 0;
single_symbol ht[HASHLENGTH];
single_symbol sym_tail = (single_symbol)0; /* The pointer to the tail of the Symbol stack */

/*function prototypes*/
/***********************
 * SYMBOL FUNCTIONS
 **********************/
static inline void add_type_and_pop_all(char sym_type, int sym_scope);
static inline void fill_sym_type_and_pop_into_hash(char* sym_name, char sym_type, int sym_scope);
static inline void create_fill_and_pop_sym(single_symbol hash[],char* sym_name, char sym_type, int sym_scope);
static inline int check_type_mismatch(char* sym_name, char expression_type);
static inline char symbol_is_declared(char* sym_name);
static inline single_symbol create_and_fill_sym(char* sym_name, char sym_type, int sym_scope);
static inline int fill_sym_type(char* sym_name, char type, int sym_scope);
static inline void pop_symbol_into_hash(single_symbol hash[]);
static inline single_symbol find_sym_in_stack(char* sym_name);
static inline void print_symbol_stack();
static inline single_symbol new_sym (void);
static inline void pop();
static inline int num_of_symbols_in_stack();

/***********************
 * HASH FUNCTIONS
 **********************/
static inline int add_sym_to_hash(single_symbol hash[], single_symbol sym);
static inline void add_symbol(symbol_t **head, single_symbol new_sym);
static inline single_symbol does_symbol_exist_in_hash(single_symbol hash[], single_symbol sym);
static inline void init_hash(single_symbol hash[]);
static inline int hasher(char*str);
static inline void print_sym(single_symbol symbol);
static inline void print_hash(single_symbol hash[]);



/*****************************************
 *            SYMBOL FUNCTIONS
 *****************************************/
/**
 * adds the type to each variable in the stack before it pops each one
 * and adds it to the hash table
 * @param sym_type 
 */
static inline void add_type_and_pop_all(char sym_type, int sym_scope){
  while(sym_tail!=(single_symbol)0){
    fprintf(out, "\n\n###DECLARE VARIABLES##\n");
    fprintf(out, "%s: .word 0 ",sym_tail->name);
    fill_sym_type_and_pop_into_hash(sym_tail->name, sym_type,sym_scope);
  }
  fprintf(out, "\n");
  return;
}


/**
 * fills the type of a single symbol and pops it from the stack before it 
 * adds it to the hash table
 * @param sym_name 
 * @param sym_type 
 */
static inline void fill_sym_type_and_pop_into_hash(char* sym_name, char sym_type, int sym_scope){
  int did_it_succeed = fill_sym_type(sym_tail->name, sym_type, sym_scope);
  if(did_it_succeed!=0){

    pop_symbol_into_hash(ht);
  }
  else{
    if(PRINT_ERRORS)  
    printf("Filling symbol type failed for symbol \"%s\" with type \"%c\".\n",sym_name, sym_type);
  }
  return;
}

/**
 * creates and fills the attributes of a single symbol using the arguments
 * once the symbol is created, it is popped and added to the hash table
 * @param hash      
 * @param sym_name  
 * @param sym_type  
 * @param sym_scope 
 */
static inline void create_fill_and_pop_sym(single_symbol hash[],char* sym_name, char sym_type, int sym_scope){
  create_and_fill_sym(sym_name, sym_type, sym_scope);
  if(sym_tail!=(single_symbol)0)
     if(PRINT_ERRORS) 
     printf("Type \"%c\" added to \"%s\"\n",sym_type,sym_name);

  pop_symbol_into_hash(hash);
}


/**
 * creates new symbol, checks if it is in the table, and returns the symbol if it is
 * else it returns 0
 * @param  sym_name        
 * @param  expression_type 
 * @return                 
 */
static inline int check_type_mismatch(char* sym_name, char expression_type){
  if(PRINT_ERRORS) 
   printf("Starting check\n");
  single_symbol temp_symbol = create_and_fill_sym(sym_name,'u',0);
  single_symbol symbol_returned = does_symbol_exist_in_hash(ht,temp_symbol);
  if(symbol_returned!=0){
    if(PRINT_ERRORS) 
      printf("TYPE of %s: %c\n",sym_name,symbol_returned->type);
    if((expression_type=='r' && symbol_returned->type=='i') || (expression_type=='i' && symbol_returned->type =='r')){
      printf("Warning: Rule 3: type mismatch -- ");
      printf("Expression checked. Expression between %s:\"%c\" and type: \"%c\" is type mismatch. type defaults to \"%c\"\n",symbol_returned->name, symbol_returned->type, expression_type,'r');
      NUM_ERRORS++;
    }
    if(symbol_returned->type == expression_type && expression_type!='r' || expression_type!='i' && symbol_returned->type !='r' || symbol_returned->type !='i'){
      if(PRINT_ERRORS) 
        printf("Expression checked. Expression between %s:\"%c\" and type: \"%c\" is legal.\n", symbol_returned->name,symbol_returned->type, expression_type);
      pop();
      return -1;
    }else {      
        printf("Error: Rule 3: type mismatch-- ");
        printf("Expression checked. Expression between %s:\"%c\" and type:\"%c\" is illegal.\n", symbol_returned->name,symbol_returned->type, expression_type);
        NUM_ERRORS++;
      /*
       printf("Exiting...\n");
       
      exit(1);
      */
    }
  }else{ 
      printf("Error: Rule 2: undeclared variable in expression-- ");
      printf("Symbol \"%s\" is undeclared. Cannot perform expression.\n",temp_symbol->name);
      NUM_ERRORS++;
    /*
       printf("Exiting...\n");
       
      exit(1);
      */
  }
  pop();
  return 0;
}


/**
 * return  whether or not a symbol has been declared
 * @param  sym_name 
 * @return          type of symbol if it was declared
 */
static inline char symbol_is_declared(char* sym_name){
  single_symbol temp_symbol = create_and_fill_sym(sym_name,'u',0);
  single_symbol symbol_returned= does_symbol_exist_in_hash(ht,temp_symbol);
  if(symbol_returned==0){
    printf("Error: Rule 2-- ");
        printf("Variable \"%s\" not declared\n", sym_name); 
        NUM_ERRORS++;
        pop();
    if(PRINT_ERRORS)
      print_symbol_stack();
    return; 
  }else{
      pop();
     return symbol_returned->type;
  }
  
}

/**
 * creates a single symbol and fills its attributes with the ones supplied in the arguments
 * @param  sym_name 
 * @param  sym_type     
 * @param  sym_type    
 * @return          single symbol on success, 0 on failure
 */
static inline single_symbol create_and_fill_sym(char* sym_name, char sym_type, int sym_scope){
  single_symbol symbol = find_sym_in_stack(sym_name);
  if(symbol!=0){
    if(PRINT_ERRORS) 
    	printf("Symbol already declared using that name.\n");
    return 0;
  }else{
    single_symbol sym = new_sym();
    sym->name = (char*)malloc(strlen(sym_name)+1);
    strcpy(sym->name,sym_name);
    sym->type = sym_type;
    sym->scope = sym_scope;
    if(PRINT_ERRORS) {
      printf("Symbol added with name: %s!\n",sym->name);
      print_symbol_stack();
    }
    return sym;
  }
}

/**
 * changes the type of an undefined symbol or throws an error if
 * symbol is not declared or already has a defined type
 * @param  sym_name 
 * @param  type     
 * @return          logical true/false of success or failure
 */
static inline int fill_sym_type(char* sym_name, char type, int sym_scope){
  single_symbol symbol = find_sym_in_stack(sym_name);
  if(symbol!=0){
    if(symbol->type != type || symbol->type=='u'){
      symbol->type = type;
      symbol->scope = sym_scope;
      if(PRINT_ERRORS) 
        printf("Added symbol type of \"%c\" to symbol \"%s\".\n",type, sym_name);
      return -1;
    }else{
        printf("Error: Rule 1-- ");
        printf("Redeclaration of symbol \"%s\"! Symbol type, \"%c\" already declared!\n",sym_name,type);
        NUM_ERRORS++;
    } 
  }else {
      printf("Error: Rule 2 fail\n");
      printf("Variable not declared\n");
      NUM_ERRORS++;
  }
  return 0;
}

/**
 * pops a single symbol into the hash table
 * @param hash [description]
 */
static inline void pop_symbol_into_hash(single_symbol hash[]){
    
    single_symbol symbol = sym_tail;
    
    if (symbol->name !=(char*)NULL && symbol->type != (char)NULL && symbol->scope >=0 )
    {
      add_sym_to_hash(hash, symbol);
      if(PRINT_ERRORS) 
        printf("Symbol \"%s\" popped and added to hash.\n",symbol->name);
      pop();
      
    }else {
      if(PRINT_ERRORS) 
        printf("Symbol not fully declared. Be sure that name, type, and scope are defined.\n");
    }
    return;
}


/**
 * locates the symbol in the current sym stack and
 * @param  sym_name 
 * @return          the symbol is returned on success, 0 on failure
 */
static inline single_symbol find_sym_in_stack(char* sym_name){
  single_symbol symbol = sym_tail;
  while ( symbol!=(single_symbol)0){
      if(!strcmp(symbol->name,sym_name)){
        return symbol;
      }
      symbol=symbol->next;
  }
  return 0;
}


/**
 * prints out the current symbol stack
 */
static inline void print_symbol_stack(){
  single_symbol symbol = sym_tail;
  printf("-----SYMBOLS----\n");
  while(symbol!=(single_symbol)0){
    printf("sym-name: %s sym-type: %c\n",symbol->name,symbol->type);
    symbol=symbol->next;
  
  }
  printf("----------------\n");
  return;
}

/**
 *allocates memory for a new symbol and 
 *sets its attributes to a NULL value
 * @return the new symbol created
 */
static inline single_symbol new_sym ()
{
  single_symbol sym;
  sym = (single_symbol) malloc (sizeof(symbol_t));
  sym->name = (char*)NULL;
  sym->type = (char)NULL;
  sym->scope = (int)NULL;
  sym->next = (single_symbol)sym_tail;
  sym_tail = sym;
  return sym;
}

/**
 * pops the tail from the stack and frees the memory
 * @return 
 */
static inline void pop(){
  single_symbol symbol = sym_tail;
  sym_tail = sym_tail->next;
  free(symbol);
  return;
}

static inline int num_of_symbols_in_stack(){
  int num_of_symbols = 0;
  single_symbol symbol = sym_tail;
  while(symbol!=(single_symbol)0){
    num_of_symbols++;
    symbol=symbol->next;
  
  }
  return num_of_symbols;
}

/*****************************************
 *            HASH FUNCTIONS
 *****************************************/

/**
 * [add_sym_to_hash description]
 * @param  hash array of symbol table linked lists
 * @param  sym  [description]
 * @return      [description]
 */
static inline int add_sym_to_hash(single_symbol hash[], single_symbol sym){
  if(does_symbol_exist_in_hash(hash,sym)!=0){
    printf("Error: Rule 1: Redeclaration of a variable-- ");
    printf("Redeclaration of variable \"%s\" where it is defined as type \"%c\" \n",sym->name,sym->type);
    NUM_ERRORS++;
  }else{
    add_symbol(&hash[hasher(sym->name)],sym);
    return 1;
  }
}

/**
 * adds a symbol to the symbol table at location head[some_index] 
 * @param head    pointer to linked list in array. passing by reference hash[#];
 * @param new_sym symbol to be added
 */
static inline void add_symbol(symbol_t **head, single_symbol new_sym){
  single_symbol sym;
  sym = (single_symbol) malloc (sizeof(symbol_t));
  sym->name = (char*)malloc(strlen(new_sym->name)+1);
  strcpy(sym->name,new_sym->name);
  sym->type = new_sym->type;
  sym->scope = new_sym->scope;

  sym->next = *head;
  *head= sym;

  return;
  //print_sym(*head );
}

/**
 * returns logical true/false whether or not variable was declared with the same name
 * and scope.
 * @param  hash array of symbol table linked lists
 * @param  sym  symbol structure
 * @return      boolean whether or not symbol was declared previously
 */
static inline single_symbol does_symbol_exist_in_hash(single_symbol hash[], single_symbol sym){
  int i=hasher(sym->name);
    single_symbol curr_node = hash[i];
    while(curr_node!=(single_symbol)0){
      if(!strcmp(sym->name, curr_node->name) && sym->scope==curr_node->scope){

        return curr_node;      
      }
        curr_node=curr_node->next;
    }
  
  return 0;
}

/**
 * initialize hash array to null values
 * @param hash array of linked lists
 */
static inline void init_hash(single_symbol hash[]){
  int hash_length = HASHLENGTH;
  int i;

  for(i =0; i<hash_length;i++){
    hash[i] = (single_symbol)0;
  }
}

/**
 *finds the total ascii 'value' of a string, char* str,
 *and returns that value as an int to be used as an 
 *index for where the symbol should be placed in the hash table
 * @param  str 
 * @return hash index for symbol 
 */
static inline int hasher(char* str){
  char s;
  int sum = 0;
  int i=0;

  while(str[i]!=(char)NULL){
    s = str[i];
    sum+= (int)s;
    i++;
  }
  if(PRINT_ERRORS)  
    printf("sum: %d\n",sum);
  return sum % 50;
}

/**
 * print the symbol and all of it's siblings
 * @param symbol struct 
 */
static inline void print_sym(single_symbol symbol){
  
  while ( symbol!=(single_symbol)0){
      printf( "Name: %s ||", symbol->name);
      printf( "Type: %c ||", symbol->type);
      printf( "Scope: %d\n", symbol->scope);
      symbol=symbol->next;
  }
      
}


/**
 * print out hash array
 * @param hash array of symbol table linked lists to be printed
 */
static inline void print_hash(single_symbol hash[]){
  int hash_length = HASHLENGTH;
  int i;
  printf("\n                      Hash Table \n");
  printf("=================================================================\n");

  for(i =0; i<hash_length;i++){
    printf("*** %d ****\n",i);
    if(hash[i]!=NULL)
      print_sym(hash[i]);
  }
}




