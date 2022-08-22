/*
Guia_0207 - v0.0. - 18 / 03 / 2022
Author: Bernardo Marques Fernandes - 774119
Para compilar em uma janela de comandos (terminal):
No Linux : g++ -o Guia0207 ./Guia0207.cpp
No Windows: g++ -o Guia0207.exe Guia0207.cpp
Para executar em uma janela de comandos (terminal):
No Linux : ./Guia0207
No Windows: Guia0207
*/
// lista de dependencias
#include "karel.hpp"
#include "io.hpp" //para entradas e saidas

// --------------------------- definicoes de metodos
/**
decorateWorld - Metodo para preparar o cenario.
@param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
    // colocar paredes no mundo
    world->set ( 4, 4, VWALL );
    world->set ( 4, 4, HWALL );
    // colocar um marcador no mundo
    world->set ( 4, 4, BEEPER );
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
        // definir dado local
        int step = 0;
        // testar se o robo esta' ativo
        if ( checkStatus ( ) )
        {
            // o agente que executar esse metodo
            // devera' virar tres vezes 'a esquerda
            for ( step = 1; step <= 3; step = step + 1 )
            {
                turnLeft( );
            } // end for
        } // end if
    } // end turnRight ( )

    /**
    moveN - Metodo para mover certa quantidade de passos.
    @param steps - passos a serem dados.
    */
    void moveN( int steps )
    {
        // definir dado local
        int step = 0;
        // testar se a quantidade de passos e' maior que zero
        for ( step = steps; step > 0; step = step - 1 )
        {
            // dar um passo
            move( );
        } // end for
    } // end moveN( )

    //doPartialTask - Metodo para especificar parte de uma tarefa.
    void doPartialTask( )
    {
        // especificar acoes dessa parte da tarefa
        moveN( 3 );
        turnLeft( );
    } // end doPartialTask( )

    //pickBeepers - metodo para pegar marcadores
    int pickBeepers()
    {
        //definir dado local
        int n = 0;
        //repetir com teste no inicio
        while (nextToABeeper())
        {
            pickBeeper();
            n = n + 1 ;
        }
        return (n);
    }

     //doSquare - metodo para especificar outro percurso
    void doSquare( )
    {
        //definir dado local
        int step = 1;
        int n = 0;
        char msg [80];

        //especificar acoes da tarefa
        while ( step <= 4)
        {
            //realizar uma parte da tarefa
            moveN (3);
            n = pickBeepers();

            //testar se a quantidade e menor que zero
            if (n > 0)
            {
                //montar a mensagem para a saida
                sprintf ( msg, "Recolhidos = %d", n);

                //solicitar a exibicao da mensagem
                show_Text (msg);
            }    
            turnRight();
            //tentar passar a proxima
            step = step+1;
        } //end while
        turnOff();
    } //end doSquare

    /**
    doTask - Relacao de acoes para o robo executar.
    */
    void doTask( )
    {
        // definir dado local
        int step = 4;
        // especificar acoes da tarefa
        while ( step > 0 )
        {
            // realizar uma parte da tarefa
            doPartialTask( );
            // tentar passar 'a proxima
            step = step - 1;
        } // end while
        // encerrar
        turnOff ( );
    } // end doTask( )

    /**
     * execute - metodo para executar um comando
     * @param action - comando a ser executado
     */
    void execute (int option)
    {
        //executar a opcao de comando
        switch (option)
        {
            case 0: //terminar
            //nao fazer nada
            break;

            case 1: //virar para a esquerda
            if (leftIsClear())
            {
                turnLeft();
            }
            break;
            
            case 2: //virar para o sul
            while (!facingSouth())
            {
                turnLeft();
            }
            break;

            case 3: //virar para a direita
            if (rightIsClear())
            {
                turnRight();
            }
            break;

            case 4: //virar para o oeste
            while (!facingWest())
            {
                turnLeft();
            }
            break;

            case 5: // mover
            if (frontIsClear())
            {
                move();
            }
            break;

            case 6: //virar para o leste
            while (!facingEast())
            {
                turnLeft();
            }
            break;

            case 7: //pegar marcador
            while (nextToABeeper())
            {
                pickBeeper();
            }
            break;

            case 8: //virar para o norte
            while (!facingNorth())
            {
                turnLeft();
            }
            break;
            
            case 9: //colocar marcador
            if (beepersInBag())
            {
                putBeeper();
            }
            break;

            default: //nenhuma das alternativas anteriores
            show_Error ("ERROR: Invalid command.");
        }
    }

    /**
     * moveI - Metodo para mover o robot interativamente
     * lista de comandos disponiveis:
     * 0 - turnOff               
     * 1 - turnLeft            2 - to South
     * 3 - turnRight           4 - to West
     * 5 - move                6 - to East
     * 6 - pickBeeper          8 - to North
     * 9 - putBeeper
     */

    /**
    *recordActions - metodo para mover o robot interativamente e
    *guardar descricao da tarefa em arquivo.
    *@param fileName - nome do arquivo
    */
    void recordActions (const char *fileName)
    {
        //definir dados
        int action;
        //definir arquivo onde gravar comandos
        std::ofstream archive (fileName);

        //repetir enquanto o comando for diferente de zero
        do
        {
            //ler opcao
            action = IO_readint ("Command?");
            //testar se a opcao e valida
            if ( 0 <= action && action <= 9)
            {
                //executar comando
                execute (action);
                //guardar o comando em arquivo
                archive <<action<< "\n";
            }
        }
        while (action != 0);
        //fechar o arquivo
        //INDISPENSAVEL para a gravacao
        archive.close();
    }

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
    decorateWorld ( "Guia0207.txt" );
    world->show ( );
    // preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia0207.txt" );// ler configuracao atual para o ambiente
    world->show ( ); // mostrar a configuracao atual
    set_Speed ( 3 ); // definir velocidade padrao
    // criar robo
    MyRobot *robot = new MyRobot( );
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot->create ( 1, 1, NORTH, 0, "Karel" );
    //executar e gravar acoes
    robot->recordActions("Tarefa0207.txt");
    // encerrar operacoes no ambiente
    world->close ( );
    // encerrar programa
    getchar ( );
    return ( 0 );
} // end main ( )
// -------------------------------------------- testes
/*
---------------------------------------------- documentacao complementar
---------------------------------------------- notas / observacoes / comentarios
---------------------------------------------- previsao de testes
---------------------------------------------- historico
Versao Data Modificacao
0.1 __/__ esboco
--------------------------------------------- testes
Versao Teste
0.1 01. (ok) identificacao de programa
0.1 02. (ok) teste da repeticao para virar a direita
0.1 03. (ok) teste da repeticao para percorrer um quadrado
0.1 04. (ok) teste pegar marcadores
0.1 05. (ok) teste contador de marcadores
0.1 06. (ok) teste com movimentos interativos
0.1 07. (ok) teste de anotar movimentos
*/