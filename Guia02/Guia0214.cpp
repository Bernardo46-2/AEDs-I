/*
Guia_0214 - v0.0. - 18 / 03 / 2022
Author: Bernardo Marques Fernandes - 774119
Para compilar em uma janela de comandos (terminal):
No Linux : g++ -o Guia0214 ./Guia0214.cpp
No Windows: g++ -o Guia0214.exe Guia0214.cpp
Para executar em uma janela de comandos (terminal):
No Linux : ./Guia0214
No Windows: Guia0214
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
    world->set ( 2, 3, VWALL );
    world->set ( 2, 4, VWALL );
    world->set ( 2, 5, VWALL );
    world->set ( 2, 6, VWALL );
    world->set ( 2, 7, VWALL );
    world->set ( 2, 8, VWALL );
    world->set ( 3, 2, HWALL );
    world->set ( 3, 8, HWALL );
    world->set ( 3, 3, VWALL );
    world->set ( 3, 4, VWALL );
    world->set ( 3, 5, VWALL );
    world->set ( 3, 6, VWALL );
    world->set ( 3, 7, VWALL );
    world->set ( 4, 2, HWALL );
    world->set ( 4, 3, VWALL );
    world->set ( 4, 4, VWALL );
    world->set ( 4, 5, VWALL );
    world->set ( 4, 6, VWALL );
    world->set ( 4, 7, VWALL );
    world->set ( 5, 2, HWALL );
    world->set ( 5, 8, HWALL );
    world->set ( 5, 3, VWALL );
    world->set ( 5, 4, VWALL );
    world->set ( 5, 5, VWALL );
    world->set ( 5, 6, VWALL );
    world->set ( 5, 7, VWALL );
    world->set ( 5, 8, VWALL );

    // colocar um marcador no mundo
    world->set ( 3, 3, BEEPER );
    world->set ( 3, 3, BEEPER );
    world->set ( 3, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 4, 3, BEEPER );
    world->set ( 4, 4, BEEPER );
    world->set ( 4, 4, BEEPER );
    world->set ( 5, 3, BEEPER );
    world->set ( 5, 3, BEEPER );
    world->set ( 5, 3, BEEPER );
    world->set ( 5, 4, BEEPER );
    world->set ( 5, 4, BEEPER );
    world->set ( 5, 5, BEEPER );

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

    //virar para tras
    void turnBack()
    {
        int step = 0;
        if (checkStatus())
        {
            for (step = 1; step <= 2; step = step + 1)
            {
                turnLeft();
            }
        }
    }

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

    //colocar marcadores
    void putBeepers(int beepers)
    {
        if (areYouHere(8,1))
        {
            if (beepersInBag())
            {
                int n = 0;
                for (n = 0; n < beepers; n = n + 1)
                {
                    putBeeper();
                }
            }
        }
    }

    //subir degrau para direita
    void stepUpRight()
    {
        while (!facingNorth())
        {
            turnLeft();
        }
        move();
        turnRight();
        move();
    }

    //descer degrau para direita
    void stepDownRight()
    {
        while (!facingEast())
        {
            turnLeft();
        }
        move();
        turnRight();
        move();
    }

    //subir degrau para esquerda
    void stepUpLeft()
    {
        while (!facingNorth())
        {
            turnLeft();
        }
        move();
        turnLeft();
        move();
    }

    //descer degrau para esquerda
    void stepDownLeft()
    {
        while (!facingWest())
        {
            turnLeft();
        }
        move();
        turnLeft();
        move();
    }

    /**
    doTask - Relacao de acoes para o robo executar.
    */
    void doTask( )
    {
        //pegar primeiro beeper (1)
        turnLeft();
        moveN(8);
        turnRight();
        moveN(3);
        turnRight();
        move();
        turnLeft();
        move();
        turnRight();
        moveN(3);
        recordBeepersLocations("Tarefa0214.txt");

        //pegar primeiro beeper (2)
        move();
        appendBeepersLocations("Tarefa0214.txt");

        //pegar segundo beeper (2)
        turnBack();
        moveN(4);
        turnLeft();
        move();
        turnLeft();
        moveN(4);
        appendBeepersLocations("Tarefa0214.txt");

        //pegar primeiro beeper (3)
        move();
        appendBeepersLocations("Tarefa0214.txt");

        //pegar segundo beeper (3)
        turnBack();
        moveN(5);
        turnLeft();
        move();
        turnLeft();
        moveN(5);
        appendBeepersLocations("Tarefa0214.txt");

        //pegar terceiro beeper (3)
        turnBack();
        moveN(5);
        turnRight();
        moveN(2);
        turnRight();
        moveN(5);
        appendBeepersLocations("Tarefa0214.txt");

        //entregar beepers
        turnBack();
        moveN(5);
        turnLeft();
        move();
        turnRight();
        move();
        turnRight();
        moveN(4);
        turnRight();
        moveN(8);
        putBeepers(14);

        //voltar para posicao inicial
        turnRight();
        moveN(7);
        turnBack();

        //encerrar
        turnOff();
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
    void recordBeepersLocations ( const char *fileName )
    {
        // definir dados
        int x, y;
        x = xAvenue();
        y = yStreet();
        // definir arquivo onde gravar comandos
        std::ofstream archive ( fileName );
        pickBeepers();
        archive << x << "\n";
        archive << y << "\n";
    } 

    /**
     * appendActions - metodo para acrescentar comandos ao arquivo e traduzi-los
     * @param fileName - nome do arquivo
     */
    void appendBeepersLocations (const char *fileName)
    {
        //definir dados
        int x, y;
        x = xAvenue();
        y = yStreet();
        //definir arquivo para receber acrescimos ao final
        std::fstream archive (fileName, std::ios::app);
        pickBeepers();
        archive << x << std::endl;
        archive << y << std::endl;
        //fechar arquivo
        //INDISPENSAVEL para a gravacao
        archive.close();
    }

    /**
     * playActions - metodo para receber comandos de arquivo
     * @param fileName - nome do arquivo
     */
    void playActions (const char *fileName)
    {
        //definir dados
        int action;
        //definir de onde ler os arquivos
        std::ifstream archive (fileName);

        //repetir enquanto houver dados
        archive>>action; // tentar ler a primeira linha
        while (!archive.eof()) //testar se nao encontrando o fim
        {
            //mostrar mais um comando
            IO_print( IO_toString( action ));
            delay (stepDelay);
            //executar mais um comando
            execute (action);
            //tentar ler a proxima linha
            archive>>action; //tentar ler a proxima linha
        }
        //fechar o arquivo
        //RECOMENDAVEL fechar para leitura
        archive.close();
    }

    /**
     * dictionary - metodo para traduzir um comando
     * @param action - comando a ser traduzido
     */
    chars dictionary (int action)
    {
        //definir dado
        static char word [80];
        strcpy (word, ""); //palavra vazia
        //identificar comando
        switch (action)
        {
            case 1: //virar para a esquerda
            strcpy (word, "turnLeft();");
            break;
            
            case 2: //virar para o sul
            strcpy (word, "faceSouth();");
            break;

            case 3: //virar para a direita
            strcpy (word, "turnRight();");
            break;

            case 4: //virar para o oeste
            strcpy (word, "faceWest();");
            break;
            
            case 5: //mover
            strcpy (word, "move();");
            break;

            case 6: //virar para o leste 
            strcpy (word, "faceEast();");
            break;

            case 7: //pegar marcador
            strcpy (word, "pickBeeper();");
            break;

            case 8: //virar para o norte
            strcpy (word, "faceNorth();");
            break;

            case 9: //colocar marcador
            strcpy (word, "putBeeper();");
            break;
        }
        //retornar palavra equivalente
        return (&(word[0]));
    }

    /**
     * translateActions - metodo para receber comandos de arquivos e traduzi-los.
     * @param fileName - nome do arquivo
     */
    void translateActions (const char *fileName)
    {
        //definir dados
        int action;
        //definir arquivo de onde ler dados
        std::ifstream archive (fileName);

        //repetir enquanto houver dados
        archive>>action; //tentar ler a primeira linha
        while (!archive.eof()) //testar se nao encontrado o fim
        {
            //tentar traduzir um comando
            IO_print (dictionary (action));
            getchar ();
            //guardar mais um comando
            execute(action);
            //tentar ler a proxima linha
            archive>>action; //tentar ler a proxima linha
        }
        //fechar o arquivo
        //RECOMENDAVEL para a leitura
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
    decorateWorld ( "Guia0214.txt" );
    world->show ( );
    // preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia0214.txt" );// ler configuracao atual para o ambiente
    world->show ( ); // mostrar a configuracao atual
    set_Speed ( 3 ); // definir velocidade padrao
    // criar robo
    MyRobot *robot = new MyRobot( );
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para cima, com zero marcadores, nome escolhido )
    robot->create ( 1, 1, EAST, 0, "Karel" );
    //executar tarefa
    robot->doTask();
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
0.1 08. (ok) teste de anotar e executar tais movimentos
0.1 09. (ok) teste para traduzir acoes
0.1 10. (ok) teste para pausar anotacoes
*/