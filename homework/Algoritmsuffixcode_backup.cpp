#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;
#include <string>
#include <stack>
#include <cmath>
 #include <fstream>




struct nodo{
     int pos;
     string s;
     struct nodo *izq, *der;
};



nodo* crearNodoHijo(string simbolo, nodo* &q, int pos){
     nodo* nuevoNodo = new(struct nodo);
     q->izq = nuevoNodo; 
     nuevoNodo->s= simbolo;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;
     nuevoNodo->pos = pos;

     return nuevoNodo;
}
int k = 0;
//stack <int> occST_stack;
//stack <int> occSA_stack;

void Recorrer (nodo* p, nodo* q,int i,int po,string str,int n){
   bool L = true;
   while(L  && p!=NULL ){
            
            
            if(p!=NULL && p->s == str.substr(po,1)){
             //letras iguales
              if(p->izq == NULL){
                 bool B = true;
                 int pos1 = p->pos;
                 int pos2 = i;
                 int j = 1;
                 p->pos = -1;
                   while(B){
                    
                    if(str.substr(pos1+j+n,1) < str.substr(i+j+n,1)){
                          
                          nodo* nuevoNodo1 = NULL;
                          nuevoNodo1 = new(struct nodo);
                          p->izq = nuevoNodo1;
                          nuevoNodo1->s= str.substr(pos1+j+n,1);
                          nuevoNodo1->der = NULL;
                          nuevoNodo1->izq = NULL;
                          nuevoNodo1->pos = pos1;
                          p=nuevoNodo1;
                          
                          nodo * nuevoNodo2 = NULL;
                          nuevoNodo2 = new(struct nodo);
                          p->der = nuevoNodo2;
                          nuevoNodo2->s= str.substr(i+j+n,1);
                          nuevoNodo2->der = NULL;
                          nuevoNodo2->izq = NULL;
                          nuevoNodo2->pos = pos2;
                          B = false;
                         }
                    else if(str.substr(pos1+j+n,1) > str.substr(i+j+n,1)){
                        
                          
                          nodo* nuevoNodo1 = NULL;
                          nuevoNodo1 = new(struct nodo);
                          p->izq = nuevoNodo1;
                          nuevoNodo1->s= str.substr(i+j+n,1);
                          nuevoNodo1->der = NULL;
                          nuevoNodo1->izq = NULL;
                          nuevoNodo1->pos = pos2;
                          p=nuevoNodo1;
                         
                          nodo* nuevoNodo2 = NULL;
                          nuevoNodo2 = new(struct nodo);
                          p->der = nuevoNodo2;
                          nuevoNodo2->s= str.substr(pos1+j+n,1);
                          nuevoNodo2->der = NULL;
                          nuevoNodo2->izq = NULL;
                          nuevoNodo2->pos = pos1;
                          B = false;
                    
                    }
                    else{
                        nodo* nuevoNodo3 = new(struct nodo);
                        p->izq = nuevoNodo3;
                        nuevoNodo3->s= str.substr(pos1+j+n,1);
                        nuevoNodo3->der = NULL;
                        nuevoNodo3->izq = NULL;
                        nuevoNodo3->pos = -1;
                        q=p;
                        p=nuevoNodo3;
                        j=j+1;
                    
                        
                    }
                 
                }
                
                 
                 
              }
              else{
                    
                     q=p;
                     p=p->izq;
                     Recorrer(p,q,i,po+1,str,n+1);
              
              
              
              }
              L = false;  
             }
            else if(p!=NULL && p->s > str.substr(po,1)){
               //change 
               if(q->izq == p){
               nodo* nuevoNodo = new(struct nodo);
               q->izq = nuevoNodo; 
               nuevoNodo->s= str.substr(po,1);
               nuevoNodo->der = p;
               nuevoNodo->izq = NULL;
               nuevoNodo->pos = i;
                
                
               }
               else{
               nodo* nuevoNodo = new(struct nodo);
               q->der = nuevoNodo; 
               nuevoNodo->s= str.substr(po,1);
               nuevoNodo->der = p;
               nuevoNodo->izq = NULL;
               nuevoNodo->pos = i;
                }
             
               L = false;
            }
            else{
             q=p;
             p=p->der;
            }
            
        
        }
        if(L && p==NULL){
            // agrega al ultimo hermano
               nodo* nuevoNodo = new(struct nodo);
               q->der = nuevoNodo; 
               nuevoNodo->s= str.substr(po,1);
               nuevoNodo->der = p;
               nuevoNodo->izq = NULL;
               nuevoNodo->pos = i;
               L = false;
        }
          
      
      
    
    
    }
void RecorrerNodoInterno(nodo* p){
nodo* q = p;        

    while(p!=NULL){
        if(p->izq!=NULL){ // nodo interno
            if(p->izq->der==NULL){ // nodo interno con un solo hijo
                q=p->izq;
                while(q!=NULL && q->der == NULL){
                p->s = p->s+q->s;
                p->izq = q->izq;
                q=p->izq;
                }
                //cout << p->s << endl;
            }
            else{
                //cout << p->s << endl;
            }
            
            if(q!=NULL){
                RecorrerNodoInterno(p->izq);
            }
        }
        else{
            //cout << p->s << endl;
        }
        p=p->der;
            
            
    }
}
    
    
void  subArray(nodo* p,int  sArray []){
        
        while(p!=NULL){
            if(p->izq!=NULL){
                 cout << p->s;
                 subArray(p->izq,sArray);
                
             }
            else{
                cout << p->s;
                sArray[k]=p->pos;
                k++;
            }
            p=p->der;
            
            
         }
        
        
     }

stack <int> locateSA(int A [], string str, string ocurr, stack <int> occSA_stack){
    int b=0;
    int s = 0;
    int m=ocurr.length();
    int t= str.length()-2;
    while(b < t){
        s=(b+t)/2;
        if(ocurr > str.substr(A[s],m)){
            b=s+1;

        }else{
            t=s;
        }
        
    }
    int e=b-1;
    t=str.length()-1;
    while(e<t){
        float result = (e+t)/float(2);
        s=round(result);
        if(ocurr==str.substr(A[s],m)){
            e=s;
        }else{
            t=s-1;
        }
    }
    while (b<=e){
        occSA_stack.push(A[b]);
        b++;
    }
    return occSA_stack;
        
}
stack <int> ArbolOcurrencia(nodo* p, stack <int> occST_stack){      
        while(p!=NULL){
            if(p->izq!=NULL){
                occST_stack = ArbolOcurrencia(p->izq,occST_stack);
                
             }
            else{
                occST_stack.push(p->pos);
            }
            p=p->der;
         }
         
         return occST_stack;
}



stack <int> locateST(string str, string ocurr, nodo* p,stack <int> occST_stack){
    
    bool L = true;
    int i=0;
    nodo* q = p;
    nodo* c = p;
    int len = 0;
    while(L && q!=NULL && i!=ocurr.length()){
         len = q->s.length();   
            if(q->s == ocurr.substr(i,len)){
                c=q;
                q=q->izq;
                i = i + len;
            }
            else{
                q=q->der;           
                if(q==NULL){
                    L=false;
                }
            
            }
            
    }
    
    if(q!=NULL && i==ocurr.length()){
        // termina en un nodo interno
    occST_stack =ArbolOcurrencia(c->izq,occST_stack);
    }
    else if (q==NULL && i==ocurr.length()){
        // termina en la ultima hoja
        
       occST_stack.push(c->pos);
    }
    else if(L  && q==NULL && i<ocurr.length()){
        // la ocurrencia sigue despues de la ultima hoja
        
        if(ocurr.substr(i,ocurr.length()-i) == str.substr(c->pos+i,ocurr.length()-i)){
        occST_stack.push(c->pos);
        }
    }
    return occST_stack;
}

    

// Function for resolve pattern matching
// stack<int> locate_brute_force(char *text, int n, char *pattern, int m){
// stack<int> locate_brute_force(string text, int n, char *pattern, int m){
stack<int> locate_brute_force(string text, int n, string pattern, int m, stack <int> occ_BF_stack){

    /*Ocurrence stack*/
    // stack <int> occ_stack;

    /*Iterate over each character in text*/
    for(int i = 0; i <= (n - m); ++i){

        /*Occurrence flag*/
        int occ = 1;

        /*Iterate over each character in patternt*/
        for(int j = 0; j < m and occ; ++j){

            /*if there is not an occurrence*/
            if(text[i + j] != pattern[j]){

                /* Change flag*/
                occ = 0;

            }                

        }

        /* If there is occurrence for that i*/
        if(occ){

            // printf("there is an occurrence in: %i\n", i);
            occ_BF_stack.push(i);
        }

    }

    return occ_BF_stack;
}


// void write_file(char *name, float *times[], int rep, int exp_num){

//  // cout << name << endl;

//  // Create file with times
//  ofstream myfile (name);

//  // If file is open
//  if (myfile.is_open()){

//      // print time array
//      for(int i = 0; i < rep; ++i){

//          for(int j = 0; j < exp_num; ++j){

//              // printf("%f\n", times_BF[i][j]);
//              // add matrix elemento to file
//              myfile << times[i][j] << "," ;
//          }

//          myfile << "\n" ;

//      }

//      // Close file
//      myfile.close();

//  }

// }

int check_correctness(stack <int> occ_BF_stack, stack <int> occST_stack, stack <int> occSA_stack ){

    int equals = 1;

    // check if size are equals
    if(!(occ_BF_stack.size() == occST_stack.size() &  occ_BF_stack.size() == occSA_stack.size())){

        printf("\nERROR: The haven't same size !!! \nBF: %i, ST: %i, SA: %i\n", occ_BF_stack.size(), occST_stack.size(), occSA_stack.size());

        equals = 0;

    }

    // printf("Brute force \n");
    // // If there is not ocurrences
 //     if(occ_BF_stack.empty()){

 //         // print user message
 //         printf("There aren't ocurrences!\n");

 //     }

 //     // If there is ocurrences
 //     else{

 //         // cout << "Pattern size: " << m << " Ocurrences : " << occ_BF_stack.size() << endl;

 //         // Print all elemnts from stack
 //         while (!occ_BF_stack.empty()) {

 //           printf("ocurrence in: %i\n", occ_BF_stack.top());

 //           // Drop ocurrence from stack
 //           occ_BF_stack.pop();

 //         }

 //     }

 //     printf("ST \n");
    // // If there is not ocurrences
 //     if(occST_stack.empty()){

 //         // print user message
 //         printf("There aren't ocurrences!\n");

 //     }

 //     // If there is ocurrences
 //     else{

 //         // cout << "Pattern size: " << m << " Ocurrences : " << occ_BF_stack.size() << endl;

 //         // Print all elemnts from stack
 //         while (!occST_stack.empty()) {

 //           printf("ocurrence in: %i\n", occST_stack.top());

 //           // Drop ocurrence from stack
 //           occST_stack.pop();

 //         }

 //     }

 //     printf("SA \n");
    // // If there is not ocurrences
 //     if(occSA_stack.empty()){

 //         // print user message
 //         printf("There aren't ocurrences!\n");

 //     }

 //     // If there is ocurrences
 //     else{

 //         // cout << "Pattern size: " << m << " Ocurrences : " << occ_BF_stack.size() << endl;

 //         // Print all elemnts from stack
 //         while (!occSA_stack.empty()) {

 //           printf("ocurrence in: %i\n", occSA_stack.top());

 //           // Drop ocurrence from stack
 //           occSA_stack.pop();

 //         }

 //     }

    return equals;

}

int  main(int argc, char *argv[]){
    
    // argument validation
    if(argc != 3){

        printf("run as ./prog_name num_repeats num_exp\n");
        exit(EXIT_FAILURE);

    }

    nodo* R;   // creado Arbol
    nodo* p;
    nodo* q;
    R = new(struct nodo);
    R->der = NULL;
    R->izq = NULL;
    R->s = ' ';
    R->pos = -1;
    
    // Random number for get pattern randomly
    int ran;

    // Get file
     // Get text
    // Read file
    // Store text in str (type = string)
    // std::ifstream t("fib41_10MB");
    std::ifstream t("english.10MB");
    std::string str2((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

    // remove this
    string str;

    // It create a scubtring because of too much time for create struct for all text
    // str = str2.substr(0,100000); // this take soo much time
    str = str2.substr(0,10); // This is ok
    // str = str2.substr(0,100000);

    // string str = "mississippi";  //AQUI ESCRIBE LA PALABRA QUE QUIERAS PROBAR.
    
    str = str + "\30"; // reemplaza el simbolo $=34 tabla ASCCI porque el el simbolo espacio es " "=31.

    /*Lenght of text and pattern*/
    int str_length = str.length();

    // CREATE SUFFIX TREE


    p=crearNodoHijo(str.substr(0,1),R,0); 
      
    int po = 0;
    int n = 0;
    q=R;

    printf("creating st of length: %i\n", str_length);

    for(int i=1; i < str_length; i++){

        printf("index %i\n", i);

        n=0;
        q=R;
        p=R->izq;
        po=i;
        Recorrer(p,q,i,po,str,n);
       
    }

    p=R->izq;

    int sArray [str_length];

    // cout << sArray << endl;
    
    // cout << "Aristas del arbol en preorden:"<<endl;

    // CREATE SUFFIX ARRAY

    subArray(p,sArray);
     
    // cout << "\n" << "Arreglo de sufijos" << "\n";
    
    // for(int i=0; i< str_length -1; i++){

    //  cout << sArray[i] << "-";   

    // }

    // cout << sArray[str_length-1];
    // cout << endl; 

    RecorrerNodoInterno(p); 
    p=R->izq;

    // cout << "palabra ingresada: ";
    // cout << str << endl;

    // DEFINE PATTERN

     // pattern
    string ocurr;

    // Number of experiments
    // int exp_num = 6
    int exp_num = atoi(argv[2]);

    // Pattern size
    int m;

    // Repetitions
    // int rep = 1000;
    int rep = atoi(argv[1]);

    // For each size of pattern
    int patterns_sizes [exp_num] = {2, 4, 8, 16, 32, 64};

    // Array for store times 
    // float times [rep][exp_num]; // + 1 is for store the method: 0: BF; 1: ST; 2: SA
    // int last_col = exp_num;
    float times_SA [rep][exp_num];
    float times_BF [rep][exp_num];
    float times_ST [rep][exp_num];

    // store time
    clock_t t_start;
    float time;


    //Locate para el arreglo
    stack <int> occSA_stack;
    // Stack for store ocurreces
    stack<int> occ_BF_stack;
    stack <int> occST_stack;

    printf("\n");

    // printf("pattern size: %i\n", patterns_sizes[1]);
    // Iterate over each pattern size
    for(int pat_size = 0; pat_size < exp_num; ++pat_size ){

        // printf("new Column \n");

        // pattern size
        m = patterns_sizes[pat_size];

        printf("New experiment with pattern size: %i\n", m);

        // printf("pattern size : %i\n", patterns_sizes[pat_size]);

        // Random number
        ran = rand() % (str_length-m);

        // printf("%i\n", ran);
        // get pattern
        // char pattern [m] = str[ran::ran + m - 1];
        ocurr = str.substr(ran, m); 

        // printf("ran: %i, str_length: %i\n", ran, str_length);
         
        // string ocurr = "Shook";  // AQUI ESCRIBE LA OCURRENCIA
         
        // cout << "buscar ocurrencia: " << endl;
        // cout << "--" << ocurr << "--" <<endl;
     

        // LOCATE ARRAY

        printf("\n");

        // Repeat algorithm rep times
        for(int i = 0; i < rep; ++i){

            // LOCATE BF 

            // get start time
            // clock_t time;
            t_start = clock();

            // Get ocurrences
            occ_BF_stack = locate_brute_force(str, str_length, ocurr, m, occ_BF_stack);

            // Get taken time
            time = (float)(clock() - t_start)/CLOCKS_PER_SEC;

            // printf("%f\n", time);

            // Add time to array
            times_BF[i][pat_size] = time;
            // times[i][pat_size] = time;
            // times[i][last_col] = 0;

            // // // removing elements from stack
            // while(!occ_BF_stack.empty()){

            //  //  If elmetns are not equals
            //  if(!(occSA_stack.top() == occ_BF_stack.top())){

            //      // error message
            //      printf("error in matching \n");

            //      // Exit from execution
            //      exit(EXIT_FAILURE);

            //  }

            //  occSA_stack.pop();

            //  occ_BF_stack.pop();

            // }
            // printf("Brute force stack");

         //     // // If there is not ocurrences
         //     if(occ_BF_stack.empty()){

         //         // print user message
         //         printf("There aren't ocurrences!\n");

         //     }

         //     // If there is ocurrences
         //     else{

         //         // cout << "Pattern size: " << m << " Ocurrences : " << occ_BF_stack.size() << endl;

         //         // Print all elemnts from stack
         //         while (!occ_BF_stack.empty()) {

         //           printf("ocurrence in: %i\n", occ_BF_stack.top());

         //           // Drop ocurrence from stack
         //           occ_BF_stack.pop();

         //         }

         //     }

            // LOCATE SA

            // get start time
            // clock_t time;
            t_start = clock();

            // Get ocurrences
            occSA_stack = locateSA(sArray,str,ocurr,occSA_stack);

            // Get taken time
            time = (float)(clock() - t_start)/CLOCKS_PER_SEC;

            // printf("%f\n", time);

            // Add time to array
            times_SA[i][pat_size] = time;
            // times[i][pat_size] = time;
         //    times[i][last_col] = 1;

            // printf("SA stack");

            // if(occSA_stack.empty()){

            //  // print user message
            //  printf("There aren't ocurrences!\n");

            // }

            // while (!occSA_stack.empty()) {

            //  printf("ocurrence in: %i\n", occSA_stack.top());

            //  occSA_stack.pop();

            // }


            // LOCATE TREE
             
            // get start time   
            // clock_t time;
            t_start = clock();

            // Get ocurrences
            occST_stack = locateST(str,ocurr,p,occST_stack); // ESTE ES EL LOCATE PARA EL ARBOL

            // Get taken time
            time = (float)(clock() - t_start)/CLOCKS_PER_SEC;

            // printf("%f\n", time);

            // Add time to array
            times_ST[i][pat_size] = time;
            // times[i][pat_size] = time;
      //       times[i][last_col] = 2;

   //          printf("ST stack\n");

            // if(occST_stack.empty()){

            //  // print user message
            //  printf("There aren't ocurrences!\n");

            // }

            // while (!occST_stack.empty()) {

            //  printf("ocurrence in: %i\n", occST_stack.top());
            //  occST_stack.pop();

            // }

            // Check if resutls are equals
            // if(!check_correctness){
            //  printf("Error\n");
            //  exit(EXIT_FAILURE);

            // }
            // cout << check_correctness(occ_BF_stack, occST_stack, occSA_stack) << endl;
            // cout << check_correctness(occ_BF_stack, occST_stack, occSA_stack) << endl;
         }


        
    }

    printf("Finishin experiments\n");

    // // Create file
    // write_file('times_BF', times_BF, rep, exp_num);
    // Create file with times
    // ofstream myfile ("times.csv");

    // // If file is open
    // if (myfile.is_open()){

    //  // print time array
    //  for(int i = 0; i < rep; ++i){

    //      for(int j = 0; j < exp_num; ++j){

    //          // printf("%f\n", times_BF[i][j]);
    //          // add matrix elemento to file
    //          myfile << times[i][j] << "," ;
    //      }

    //      myfile << "\n" ;

    //  }

    //     // Close file
    //     myfile.close();

    // }

    printf("Creating file\n");
    // Create file with times
    ofstream myfile ("times_BF.csv");

    // If file is open
    if (myfile.is_open()){

        // print time array
        for(int i = 0; i < rep; ++i){

            for(int j = 0; j < exp_num; ++j){

                // printf("%f\n", times_BF[i][j]);
                // add matrix elemento to file
                myfile << times_BF[i][j] << "," ;
            }

            myfile << "\n" ;

        }

        // Close file
        myfile.close();

    }

    // Create file with times
    ofstream myfile1 ("times_SA.csv");

    // If file is open
    if (myfile1.is_open()){

        // print time array
        for(int i = 0; i < rep; ++i){

            for(int j = 0; j < exp_num; ++j){

                // printf("%f\n", times_BF[i][j]);
                // add matrix elemento to file
                myfile1 << times_SA[i][j] << "," ;
            }

            myfile1 << "\n" ;

        }

        // Close file
        myfile1.close();

    }

    // Create file with times
    ofstream myfile2 ("times_ST.csv");

    // If file is open
    if (myfile2.is_open()){

        // print time array
        for(int i = 0; i < rep; ++i){

            for(int j = 0; j < exp_num; ++j){

                // printf("%f\n", times_BF[i][j]);
                // add matrix elemento to file
                myfile2 << times_ST[i][j] << "," ;
            }

            myfile2 << "\n" ;

        }

        // Close file
        myfile2.close();

    }

    printf("Finish program execution\n");
    // printf("Time BF: \n");

    // // print time array
    // for(int i = 0; i < rep; ++i){

    //  for(int j = 0; j < exp_num; ++j){

    //      printf("%f ", times_BF[i][j]);
    //  }

    //  printf("\n");

    // }

    return 0;
 
}
  
 
