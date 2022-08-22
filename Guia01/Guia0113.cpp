/*
Guia0113 - v0.0. - 08/03/2022
Author: Bernardo Marques Fernandes - 774119

Para compilar em uma janela de comandos (terminal):
No Linux : g++ -o Guia0113 ./Guia0113.cpp
No Windows: g++ Guia0113.cpp -o Guia0113.exe
Para executar em uma janela de comandos (terminal):
No Linux : ./Guia0113
No Windows: Guia0113
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
    // colocar um marcador no mundo
    world->set ( 3, 3, BEEPER );
    world->set ( 6, 3, BEEPER );
    world->set ( 6, 6, BEEPER ); 
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
       moveN(2);
   } //end doPartialTask()
   void doPartialTask2()
   {
       moveN(3);
   }
   void doPartialTask3()
   {
       doPartialTask();
       doPartialTask2();
   }
    /**
     doTask - Relacao de acoes para qualquer robo executar
     * */
    void doTask()
    {
        //especificar acoes da tarefa
        turnLeft();
        doPartialTask3();
        turnRight();
        doPartialTask3();
        if (nextToABeeper())
        {
            pickBeeper();
        }
        turnRight();
        doPartialTask2();
        if (nextToABeeper())
        {
            pickBeeper();
        }
        turnRight();
        doPartialTask2();
        if (nextToABeeper())
        {
            pickBeeper();
        }
        turnLeft();
        doPartialTask();
        turnLeft();
        doPartialTask2();
        if (nbeepers() > 0)
        {
            putBeeper();
        }
        turnLeft();
        turnLeft();
        moveN(1);
        if (nbeepers() > 0)
        {
            putBeeper();
        }
        moveN(1);
        if (nbeepers() > 0)
        {
            putBeeper();
        }
        doPartialTask2();
        turnLeft();
        turnLeft();
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
    decorateWorld ( "Guia0113.txt" );
    world->show ( );
    // preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia0113.txt" );// ler configuracao atual para o ambiente
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