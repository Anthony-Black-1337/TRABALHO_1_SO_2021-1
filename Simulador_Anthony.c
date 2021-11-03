//#include <Simulador.h> 
#include <stdio.h>
#include <stdlib.h>

#define TAM 20 // o tamanho da memória

   //Inicializa o enum 
      typedef enum {
         ERR_OK = 0,
            //...
         ERR_CPU_PARADA = 1,    // CPU executou instrução PARA
         ERR_CPU_INSTR_INV = 2, // tentativa de execução de instrução inexistente
            //...
      } err_t;

   //Inicializa as structs
      struct mem_cria 
      {
         int mem[TAM];
      };
      typedef struct mem_cria MEM;

      struct es_cria 
      {
         int es[TAM];
      };
      typedef struct es_cria ES;

      struct cpu_cria 
      {
         int cpu[TAM];
      };
      typedef struct cpu_cria CPU;

      struct cpu_estado_cria 
      {
         int estado[TAM];
      };
      typedef struct cpu_estado_cria CPU_EST;

   //Inicializa as Funcoes

      int mem_escreve(MEM mem_t,int i, int* progr);
      int cpu_altera_estado(CPU cpu_t, CPU_EST cpu_estado_t);
      int cpu_altera_memoria(CPU cpu_t, MEM mem_t);
      int cpu_altera_es(CPU cpu_t, ES es_t);

   void imprime_estado(CPU_EST cpu_estado_t)
   {
     printf("\nimprime_estado = OK\n");
   }

int main()
{
   //estruturas criadoras
      struct mem_cria mem_t;
      struct es_cria es_t;
      struct cpu_cria cpu_t;
      struct cpu_estado_cria cpu_estado_t;

   // programa para executar na nossa CPU
      int progr[TAM] = { 2, 0, 7, 2, 10, 5, 17,    //  0      x=0; l=10
                         8, 20, 1,                 //  7 ali: print x
                         9, 8, 11, 17, 18, 7,      // 10      if ++x != l goto ali
                         1,                        // 16      FIM
                         0                         // 17 aqui tá o "l"
                        };

   // copia o programa para a memória
      for (int i = 0; i < TAM; i++) 
      {
        if (mem_escreve(mem_t, i, progr) != ERR_OK) 
        {
          printf("Erro de memoria, endereco %d\n", i);
          exit(1);
        }
      }

   //inicializa a CPU com as variáveis criadas
      cpu_altera_estado(cpu_t, cpu_estado_t);
      cpu_altera_memoria(cpu_t, mem_t);
      cpu_altera_es(cpu_t, es_t);

   // executa uma instrução por vez até parar
      /*while (true) {
        imprime_estado(cpu_estado(cpu));
        err_t err = cpu_executa_1(cpu);
        if (err != ERR_OK) {
          printf("Erro na execução: %d\n", err);
          printf("Estado final:\n");
          imprime_estado(cpu_estado(cpu));
          break;
        }
      }*/

   
   return 0;
} 
int mem_escreve(MEM mem_t, int i, int* progr)
{
   
   mem_t.mem[i] = progr[i];

   printf("[%d]-", mem_t.mem[i]);

   return 0;
}

int cpu_altera_estado(CPU cpu_t, CPU_EST cpu_estado_t)
{
   printf("\ncpu_altera_estado = OK\n");
   return 0;
}
int cpu_altera_memoria(CPU cpu_t, MEM mem_t)
{
   printf("\ncpu_altera_memoria = OK\n");
   return 0;
}
int cpu_altera_es(CPU cpu_t, ES es_t)
{
   printf("\ncpu_altera_es = OK\n");
   return 0;
}