/*
Guia03E1 - v0.0. - 26 / 03 / 2022_
Author: Bernardo Marques Fernandes - 774119
Para compilar em uma janela de comandos (terminal):
No Linux : g++ -o Guia03E1 ./Guia03E1.cpp
No Windows: g++ -o Guia03E1.exe Guia03E1.cpp
Para executar em uma janela de comandos (terminal):
No Linux : ./Guia03E1
No Windows: Guia03E1
*/
// lista de dependencias
#include "karel.hpp"
#include "io.hpp"

// --------------------------- definicoes de metodos
/**
decorateWorld - Metodo para preparar o cenario.
@param fileName - nome do arquivo para guardar a descricao.
*/
void decorateWorld ( const char* fileName )
{
    // colocar paredes no mundo
    world->set ( 1, 5, VWALL );
    world->set ( 1, 6, VWALL );
    world->set ( 8, 5, VWALL );
    world->set ( 8, 6, VWALL );
    world->set ( 2, 4, HWALL );
    world->set ( 3, 4, HWALL );
    world->set ( 4, 4, HWALL );
    world->set ( 5, 4, HWALL );
    world->set ( 6, 4, HWALL );
    world->set ( 7, 4, HWALL );
    world->set ( 8, 4, HWALL );
    world->set ( 2, 6, HWALL );
    world->set ( 3, 6, HWALL );
    world->set ( 4, 6, HWALL );
    world->set ( 5, 6, HWALL );
    world->set ( 6, 6, HWALL );
    world->set ( 7, 6, HWALL );
    world->set ( 8, 6, HWALL );
    world->set ( 2, 5, HWALL );
    world->set ( 3, 5, HWALL );
    world->set ( 4, 5, HWALL );
    world->set ( 6, 5, HWALL );
    world->set ( 7, 5, HWALL );
    world->set ( 8, 5, HWALL );
    // colocar um marcador no mundo
    world->set ( 2, 5, BEEPER );
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

    void turnBack()
    {
        if (checkStatus ())
        {
            turnLeft();
            turnLeft();
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
        } // end if
    } // end moveN( )

    /**
    countCommands - Metodo para contar comandos de arquivo.
    @return quantidade de comandos
    @param fileName - nome do arquivo
    */
    int countCommands( const char * fileName )
    {
        // definir dados
        int x = 0;
        int length = 0;
        // abrir arquivo para leitura
        std::ifstream archive ( fileName );
        // repetir enquanto houver dados
        archive >> x; // tentar ler o primeiro
        while ( ! archive.eof ( ) )
        {
            // contar mais um comando lido
            length = length + 1;
            // tentar ler o proximo
            archive >> x;
        } // end while
        // fechar o arquivo
        archive.close( );
        //retornar resultado
        return (length);
    } // end countCommands( )

    /**
    readCommands - Metodo para receber comandos de arquivo.
    @return grupo formado por todos os comandos
    @param fileName - nome do arquivo
    */
    int readCommands( int commands [], const char * fileName )
    {
        // definir dados
        int x = 0;
        int action = 0;
        int length = 0;
        // abrir arquivo para leitura
        std::ifstream archive ( fileName );
        //obter a quantidade de comandos
        length = countCommands (fileName);
        //criar um armazenador para os comandos
        if (length < MAX_COMMANDS)
        {
            //repetir para a quantidade de comandos
            for (x=0; x<length; x=x+1)
            {
                //tentar ler a aproxima linha
                archive>>action;
                //guardar um comando na posicao (x) do armazenador
                commands[x] = action;
            }//end for
            //fechar o arquivo
            //INDISPENSAVEL para a gravacao
            archive.close();
        }//end if
        //retornar quantidade de comandos lidos
        return (length);
    } // end countCommands( )

    /**
    execute - Metodo para executar um comando.
    @param action - comando a ser executado
    */
    void execute( int option )
    {
        // executar a opcao de comando
        switch ( option )
        {
            case 0: // terminar
            // nao fazer nada
            break;
            
            case 1: // turn around corner left
            if ( leftIsClear ( ) )
            {
                turnLeft( );
            } // end if
            break;

            case 2: // virar para o sul
            while ( ! facingSouth( ) )
            {
                turnLeft( );
            } // end while
            break;
            
            case 3: //turn around
            if ( rightIsClear ( ) )
            {
                turnRight( );
            } // end if
            break;
            
            case 4: // virar para o oeste
            while ( ! facingWest( ) )
            {
                turnLeft( );
            } // end while
            break;
            
            case 5: // mover
            if ( frontIsClear ( ) )
            {
                move( );
            } // end if
            break;
            
            case 6: // virar para o leste
            while ( ! facingEast( ) )
            {
                turnLeft( );
            } // end while
            break;
            
            case 7: // pegar marcador
            if ( nextToABeeper( ) )
            {
                pickBeeper( );
            } // end if
            break;
            
            case 8: // virar para o norte
            while ( ! facingNorth( ) )
            {
                turnLeft( );
            } // end while
            break;
            
            case 9: // colocar marcador
            if ( beepersInBag( ) )
            {
                putBeeper( );
            } // end if
            break;
            
            default:// nenhuma das alternativas anteriores
            // comando invalido
            show_Error ( "ERROR: Invalid command." );
        } // end switch
    } // end execute( )

    /**
    metodo para executar comandos de arquivo.
    @param length - quantidade de comandos
    @param commands - grupo de comandos para executar
    */
    void doCommands ( int length, int commands [ ] )
    {
        // definir dados
        int action = 0;
        int x = 0;
        // repetir para a quantidade de comandos
        for ( x = 0; x < length; x = x + 1 )
        {
            // executar esse comando
            execute( commands [ x ] );
        } // end for
    } // end doCommands( )

    /**
     * doTask - Metodo para executar os comandos de arquivo
     * @param fileName - nome do arquivo
     */

    void doTask1() //J
    {
        //pegar beeper 
        halfPathLeft();
        turnLeft();
        move();
        halfPathLeft();
        pickBeeper();

        //ir ao ponto de encontro 
        halfPathRight();
        turnLeft();
        move();
    }

    void doTask2() //K
    {
        //ir ao ponto de encontro 
        halfPathLeft();
        turnRight();
        move();
    }

    void doTask3() //J
    {
        //colocar beeper
        if (nextToARobot())
        {
            putBeeper();
        }
    }

    void doTask4() //K
    {
        //pegar beeper
        if (nextToABeeper())
        {
            pickBeeper();
        }
        
        //entregar beeper
        turnLeft();
        turnLeft();
        move();
        halfPathRight();
        putBeeper();
        
        //ir para posicao final
        halfPathLeft();
        turnRight();
        move();
        halfPathLeft();
        turnLeft();
        turnLeft();
    }

    void doTask5() //J
    {
        halfPathRight();
    }

    void doActions(int option)
    {
        switch (option)
        {
            case 0:
            break;

            case 1:
            doTask1();
            break;

            case 2:
            doTask2();
            break;

            case 3:
            doTask3();
            break;

            case 4:
            doTask4();
            break;

            case 5:
            doTask5();
            break;

            default:// nenhuma das alternativas anteriores
            // comando invalido
            show_Error ( "ERROR: Invalid command." );
        }
    }

    void readActions (const char * fileName)
    {
        int action;
        std::ifstream archive (fileName);
        archive>>action;
        doActions (action);
        archive.close();
    }

    /**
     * mapWorld - Metodo para o robot explorar o mundo e fazer um mapa
     * @param map - arranjo bidemensional (matriz) onde guardar o mapa
     */
    void mapWorld (int map [] [WIDTH])
    {
        //definir dados locais
        int avenue = 0, street = 0;
        int beepers = 0;
        char message [80];

        //obter o tamanho do mundo, se existir
        if (world != nullptr)
        {
            //informar o tamanho do mundo
            message [0] = '\0';  //limpar a mensagem
            sprintf (message, "World is %dx%d", world->avenues(), world->streets());
            show_Text (message);

            //percorrer o mapa procurando marcadores
            for (street = 1; street <= world->streets(); street = street + 1)
            {
                for (avenue = 1; avenue <= world->avenues(); avenue = avenue + 1)
                {
                    //limpar posicao no mapa
                    map [street-1] [avenue-1] = 0;
                    //se proximo a um marcador
                    if (nextToABeeper())
                    {
                        //informar marcador nessa posicao
                        message[0] = '\0';
                        sprintf (message, "Beeper at (%d,%d)", avenue, street);
                        show_Text (message);
                        //marcar posicao no mapa
                        map [street-1] [avenue-1] = 1;
                        //encontrado mais um marcador
                        beepers = beepers + 1;
                    } //end if
                    //mover para a proxima posicao
                    if (avenue < world->avenues())
                    {
                        move();
                    } //end if
                } //end for
                turnLeft();
                turnLeft();
                moveN( world->avenues()-1);
                if (street < world->streets())
                {
                    turnRight();
                    move();
                    turnRight();
                } //end if
            } //end for
        } //end if
    } //end mapWorld

    /**
     * saveMap - Metodo para guardar um mapa em arquivo
     * @param filename - nome do arquivo onde guardar o mapa
     * @param map - arrnajo bidimensional (matriz) com o mapa
     */
    void saveMap (const char* fileName, int map [] [WIDTH])
    {
        //definir dados locais
        int avenue = 0, street = 0;
        //abrir arquivo para gravacao
        std::ofstream archive (fileName);

        //testar se ha informacao
        if (world != nullptr)
        {
            //guardar o tamanho do mundo
            archive<<world->avenues()<<"\n";
            archive<<world->streets()<<"\n";

            //percorrer o mundo procurando beepers
            for (street=1; street<=world->streets(); street=street+1)
            {
                for (avenue=1; avenue<=world->avenues(); avenue=avenue+1)
                {
                    //guardar informacao no arquivo
                    if (map [street-1] [avenue-1] == 1)
                    {
                        archive<<avenue<<std::endl;
                        archive<<street<<std::endl;
                        archive<<map [street-1] [avenue-1] <<std::endl;
                    }//end if
                }//end for
            }//end for
            //fechar o arquivo
            archive.close();
        }//end if
    }//end saveMap

    /**
     * showMap - Metodo para ler um mapa em arquivo
     * @param avenues - largura do mapa
     * @param streets - altura do mapa
     * @param map - arranajo bidimensional (matriz) com o mapa
     */
    void showMap (int avenues, int streets, char map [] [WIDTH])
    {
        //definir dados
        int x=0, y=0;

        //percorrer o mundo procurando marcadores
        clrscr();
        std::cout<<" Mapa de marcadores\n\n";

        std::cout<<" ";
        for (x=0; x<streets; x=x+1)
        {
            std::cout<<(x+1);
        }//end for

        std::cout<<(y+1);
        for (y=0; y<streets; y=y+1)
        {
            std::cout<<map [y] [x];
        }//end for
        IO_pause ("Apertar ENTER para continuar.");
    }//end showMap

    /**
     * readMap - Metodo para ler um mapa em arquivo.
     * @param fileName - nome do arquivo com mapa
     */
    void readMap (const char* fileName)
    {
        //definir dados
        int avenue = 0, street = 0;
        int avenues = 0, streets = 0;
        int x = 0, y = 0, z = 0;
        std::ifstream archive (fileName);

        //reservar area para guardar o maior mapa possivel
        char map [HEIGHT] [WIDTH];

        //obter o tamanho do mundo
        archive>>avenues;
        archive>>streets;

        //testar configuracao do mapa
        if ((0 < avenues && avenues <= world->width) && (0 < streets && streets <= world->height))
        {
            //percorre o mundo procurando marcadores
            for (y=0; y<streets; y=y+1)
            {
                for (x=0; x<avenues; x=x+1)
                {
                    map [y] [x] = '.';
                }//end for
            }//end for

            //repetir enquanto houver dados
            archive>>avenue;  //tentar ler a primeira linha
            while (!archive.eof())  //testar se nao encontrado o fim
            {
                //contar mais um comando
                archive>>street;
                archive>>z;
                //testar se informacoes validas
                if ((1 <= avenue && avenue <= world->width ) && (1 <= street && street <= world->height) && (z==1))
                {
                    map [street-1] [avenue-1] = 'X';
                }//end if
                archive>>avenue; //tentar ler a proxima linha
            }//end while
            //fechar o arquivo
            //RECOMENDAVEL para a leitura
            archive.close();

            //mostrar mapa
            showMap (avenues, streets, map);
        }//end if

    }//end readMap

    void recordBeeperLocation (const char* fileName)
    {
        int beeper = 0;
        int quantidade = 0;
        int x = xAvenue();
        int y = yStreet();
        std::fstream archive (fileName, std::ios::app);
        while (nextToABeeper())
        {
            pickBeeper();
            quantidade = quantidade + 1;
        }
        archive<<x<<std::endl;
        archive<<y<<std::endl;
        archive<<quantidade<<std::endl;
        archive.close();
    }

    void putBeepers()
    {
        while (beepersInBag())
        {
            putBeeper();
        }
    }

    void clearTxtFile ()
    {
        std::ofstream archive;
        archive.open("Tarefa03E1.txt", std::ofstream::out | std::ofstream::trunc);
        archive.close(); 
    }

    void halfPathRight ()
    {
        while (!facingEast())
        {
            turnLeft();
        }
        moveN(3);
    }

    void halfPathLeft ()
    {
        while (!facingWest())
        {
            turnLeft();
        }
        moveN(3);
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
    decorateWorld ( "Guia03E1.txt" );
    world->show ( );
    // preparar o ambiente para uso
    world->reset ( ); // limpar configuracoes
    world->read ( "Guia03E1.txt" );// ler configuracao atual para o ambiente
    world->show ( ); // mostrar a configuracao atual
    set_Speed ( 3 ); // definir velocidade padrao
    // criar robo
    MyRobot *robot1 = new MyRobot( );
    MyRobot *robot2 = new MyRobot( );
    // posicionar robo no ambiente (situacao inicial):
    // posicao(x=1,y=1), voltado para direita, com zero marcadores, nome escolhido )
    robot1->create ( 8, 5, EAST, 0, "Karel" ); //'K'
    robot2->create ( 8, 6, EAST, 0, "Jarel" ); //'J'
    //executar tarefa
    robot2->readActions("Tarefa03E1-1.txt");
    robot1->readActions("Tarefa03E1-2.txt");
    robot2->readActions("Tarefa03E1-3.txt");
    robot1->readActions("Tarefa03E1-4.txt");
    robot2->readActions("Tarefa03E1-5.txt");    
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
0.1 __/__ esboco
---------------------------------------------- testes
Versao Teste
0.1 01. ( OK ) identificacao de programa
*/