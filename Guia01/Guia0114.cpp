/*
Guia0114 - v0.0. - 08/03/2022
Author: Bernardo Marques Fernandes - 774119

Para compilar em uma janela de comandos (terminal):
No Linux : g++ -o Guia0114 ./Guia0114.cpp
No Windows: g++ Guia0114.cpp -o Guia0114.exe
Para executar em uma janela de comandos (terminal):
No Linux : ./Guia0114
No Windows: Guia0114
*/
// lista de dependencias
#include "karel.hpp" //(comentário: necessario estar na mesma pasta)
// --------------------------- definicoes de metodos
/**
decorateWorld - Metodo para preparar o cenario.
@param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
    // colocar paredes no mundo
    world->set ( 3, 2, HWALL );
    world->set ( 4, 2, HWALL );
    world->set ( 5, 2, HWALL );
    world->set ( 3, 6, HWALL );
    world->set ( 4, 6, HWALL );
    world->set ( 5, 6, HWALL );
    world->set ( 5, 3, VWALL );
    world->set ( 5, 4, VWALL );
    world->set ( 5, 5, VWALL );
    world->set ( 2, 3, VWALL );
    world->set ( 2, 4, VWALL );
    world->set ( 2, 5, VWALL );
    world->set ( 2, 6, VWALL );
    // colocar um marcador no mundo
    world->set ( 2, 3, BEEPER );
    world->set ( 6, 3, BEEPER );
    world->set ( 3, 7, BEEPER ); 
    // salvar a configuracao atual do mundo
    world->save( fileName );
} // decorateWorld ( )
/**
Classe para definir robo particular (MyRobot),
a partir do modelo generico (Robot)
Nota: Todas as definicoes irao valer para qualquer outro robo
criado a partir dessa nova descricao de modelo.
*/
class MyRobot : public Robot
{
    public:
    /**
    turnRight - Procedimento para virar 'a direita.
    */
    void turnRight ( )
    {
        // testar se o robo esta' ativo
        if ( checkStatus ( ) )
        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            turnLeft ( );
            turnLeft ( );
            turnLeft ( );
        } // end if
    } // end turnRight ( )

     void turnBack ( )
   {
       if (checkStatus ( ) )
       {
           turnLeft ( );
           turnLeft ( );
       }
   }

    /**
     * @brief moveN - Metodo para mover certa quantidade de passos.
     * @param steps - passos a serem dados.
    */
   void moveN( int steps)
   {
       //definir dado local
       int step = 0;
       //repetir contando e testando ate' atingir a quantidade de passos
       for ( step = 1; step <= steps; step = step + 1 ) //outra forma de repetir
       {
           //dar um passo por vez
           move();
       }   //enf if
   } //end moveN();

    /**
     doPartialTask - Metodo para descrever parte de uma tarefa.
    */

   void doPartialTask()
   {
       //especificar acoes dessa parte da tarefa
       moveN(1);
   } //end doPartialTask()

   void doPartialTask2()
   {
       moveN(2);
   }

   void doPartialTask3()
   {
       doPartialTask();
       doPartialTask2();
   }

   void doPartialTask4()
   {
       doPartialTask();
       doPartialTask3();
   }
    /**
     doTask - Relacao de acoes para qualquer robo executar
     * */

    void doTask()
    {
        //especificar acoes da tarefa
        turnLeft();
        doPartialTask2();
        turnRight();
        doPartialTask();
        if (nextToABeeper())
        {
            pickBeeper();
        }
        turnLeft();
        doPartialTask4();
        turnRight();
        doPartialTask();
        if (nextToABeeper())
        {
            pickBeeper();
        }
        doPartialTask3();
        turnRight();
        doPartialTask4();
        if (nextToABeeper())
        {
            pickBeeper();
        }
        turnBack();
        doPartialTask3();
        turnLeft();
        doPartialTask2();
        turnLeft();
        doPartialTask3();
        while (nbeepers() > 0)
        {
            putBeeper();
        }
        turnBack();
        doPartialTask3();
        turnRight();
        doPartialTask2();
        turnRight();
        doPartialTask4();
        doPartialTask();
        turnRight();
        doPartialTask4();
        doPartialTask();
        turnBack();
        //encerrar
        turnOff(); //desligar-se
    }//end doTask()
    
     
}; // end class MyRobot
// --------------------------- acao principal
/**
Acao principal: executar a tarefa descrita acima.
*/
int main ( )
{
    // definir o contexto
    // criar o ambiente e decorar com objetos
    // OBS.: executar pelo menos uma vez,
    // antes de qualquer outra coisa
    // (depois de criado, podera' ser comentado)
    world->create ( "" ); // criar o mundo
    decorateWorld ( "Guia0114.txt" );
    world->show ( );
    // preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia0114.txt" );// ler configuracao atual para o ambiente
    world->show ( ); // mostrar a configuracao atual
    set_Speed ( 3 ); // definir velocidade padrao
    // criar robo
    MyRobot *robot = new MyRobot( );
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create ( 1, 1, EAST, 0, "Karel" );
    // executar tarefa
    robot->doTask();
    // encerrar operacoes no ambiente
    world->close ( );
    // encerrar programa
    getchar ( );
    return ( 0 );
} // end main ( )
// ------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 11/03 esboco
---------------------------------------------- testes
Versao Teste
0.1 0.1 (ok) teste inicial
0.2 0.1 (ok) teste da tarefa
0.3 0.1 (ok) teste da tarefa parcial
0.4 0.1 (ok) teste do apanhar marcador
0.5 0.1 (ok) teste do colocar marcador
0.6 01. (ok) teste da repeticao de movimento
0.7 01. (ok) teste com marcador na posicao (4,4)
    02. (ok) teste sem marcador na posicao (4,4)
0.8 01. (ok) teste com a quantidade de marcadores
0.9 01. (ok) teste com outra forma de repeticao
1.0 01. (ok) teste com outra forma de alternativa
*/