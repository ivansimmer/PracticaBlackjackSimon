#include <iostream>
using namespace std;
int puntuacionJugador;
int puntuacionCroupier;

void Normas() {

    cout << "Las normas del Blackjack son simples, y consisten en lo siguiente: \n";
    cout << "   1. La puntuacion de las cartas del 2 al 10 tienen el mismo valor que su numero.\n";
    cout << "   2. El AS puede valer un 1 o un 11 segun lo que el jugador o banca prefiera.\n";
    cout << "   3. Las figuras J, Q, y K valen 10 puntos.\n";
    cout << "   4. El jugador gana en caso de alcanzar 21 puntos y que el croupier no empate, que no se pase de 21, o tenga una puntuacion menor a 21 pero el croupier se pase.\n";
    cout << "   5. El jugador empata en caso de alcanzar 21 puntos y que el croupier lo empate a 21.\n";
    cout << "   6. El jugador pierde en caso de superar los 21 puntos, o si tiene una puntuacion menor a 21 pero la banca tiene una mayor puntuacion sin superar los 21.\n";
    cout << "\n";

}

void Funcionamiento() {

    cout << "El funcionamiento del Blackjack es el siguiente:\n";
    cout << "   1. El croupier reparte dos cartas al jugador, y, posteriormente una a si mismo.\n";
    cout << "   2. Si el jugador tiene menos de 21 puntos puede pedir nuevas cartas hasta que deciada plantarse, y llegue o supere los 21 puntos.\n";
    cout << "   3. A continuacion, el croupier coge cartas hasta que mejore, o empate la puntuacion en caso de ser 21, del jugador. En caso de pasarse de los 21 puntos, pierde automaticamente.\n";
    cout << "\n";

}

void Intro() {

    int opcNormas;
    int opcFuncionamiento;

    cout << "Hola! Bienvenido al Blackjack Simon\n";
    cout << "Conoces las normas del Blackjack?\n";
    cout << "1 - Si | 2 - No, mejor explicamelas.\n";
    cin >> opcNormas;
    cout << "\n";

    if (opcNormas == 1) {

        cout << "Esta bien, sigamos.\n";
        cout << "\n";
    }
    else if (opcNormas == 2) {

        Normas();
        cout << "-------------------------------------------------\n";
        cout << "\n";

    }
    else {

        cout << "Opcion incorrecta.\n";
        cout << "\n";
        Intro();

    }

    cout << "Conoces el funcionamiento del juego?\n";
    cout << "1 - Si | 2 - No, explicame como va.\n";
    cin >> opcFuncionamiento;
    cout << "\n";

    if (opcFuncionamiento == 1) {

        cout << "Esta bien, sigamos.\n";
        cout << "\n";

    }
    else if (opcFuncionamiento == 2) {

        Funcionamiento();
        cout << "----------------------------------------------- \n";
        cout << "\n";

    }
    else {

        cout << "Opcion incorrecta.\n";
        cout << "\n";
        Intro();

    }

    cout << "Con todo lo anterior aclarado, que comience el juego!\n";
    cout << "\n";
    cout << "------------------------------------------------------- \n";
    cout << "\n";
}

void EleccionPalos() {

    string arrayPalos[] = { "Picas", "Rombos", "Treboles", "Corazones" };
    int numPalos = rand() % 4; // Genera un valor entre 0 y 3

    if (numPalos == 0) {

        cout << string(arrayPalos[0]) << ".\n";

    }
    else if (numPalos == 1) {

        cout << string(arrayPalos[1]) << ".\n";

    }
    if (numPalos == 2) {

        cout << string(arrayPalos[2]) << ".\n";

    }
    if (numPalos == 3) {

        cout << string(arrayPalos[3]) << ".\n";

    }
}

void SaleAsCroupier() {

    if ((puntuacionCroupier + 11) < 21) {

        cout << "El croupier ha elegido usar el As con 11 puntos\n";
        puntuacionCroupier = puntuacionCroupier + 11;

    }
    else {
        cout << "El croupier ha elegido usar el As con 1 punto\n";
        puntuacionCroupier = puntuacionCroupier + 1;
    }
}

void SaleAs() {

    int opcAs;

    cout << "Como quieres usarlo?\n";
    cout << "1 - 1 punto | 2 - 11 puntos";
    cout << "\n";
    cin >> opcAs;

    if (opcAs == 1) {

        cout << "Has elegido usar el As con 1 punto";
        puntuacionJugador = puntuacionJugador + 1;
        cout << "\n";

    }
    else if (opcAs == 2) {

        cout << "Has elegido usar el As con 11 puntos";
        puntuacionJugador = puntuacionJugador + 11;
        cout << "\n";

    }
}

void LogicaFin() {
    if (puntuacionJugador > 21) {
        cout << "\n";
        cout << "Te has pasado de 21 puntos. \n";
        cout << "Has perdido, gana el croupier.\n";
        cout << "Mucha suerte para la proxima vez. En Blackjack Simon te esperamos\n";
        exit(0);
    }
    else if (puntuacionCroupier > 21) {
        cout << "\n";
        cout << "El croupier se ha pasado de 21 puntos. \n";
        cout << "Has ganado, pierde el croupier.\n";
        cout << "Felicidades por tu victoria. Nada sienta mejor que ganar a la banca. Aqui te esperamos para la proxima.\n";
        exit(0);
    }
    else if (puntuacionCroupier == 21 && puntuacionJugador) {
        cout << "\n";
        cout << "El croupier te ha igualado los puntos. Hay empate.\n";
        cout << "Mucha suerte para la proxima vez. En Blackjack Simon todo puede ocurrir.\n";
        exit(0);
    }
    else if (puntuacionCroupier < 22 && puntuacionCroupier > puntuacionJugador) {
        cout << "\n";
        cout << "El croupier ha superado tus puntos sin pasarse de 21.\n";
        cout << "El croupier gana, jugador pierde.\n";
        cout << "Suerte para la proxima vez. En Blackjack Simon te esperamos\n";
        exit(0);
    }
    else if (puntuacionJugador < 22 && puntuacionJugador > puntuacionCroupier) {
        cout << "\n";
        cout << "La puntuacion del croupier es inferior a tus puntos sin pasarse de 21.\n";
        cout << "El croupier pierde, jugador gana.\n";
        cout << "Felicidades por la victoria. En Blackjack Simon te esperamos\n";
        exit(0);
    }
}

void EleccionCartaCroupier() {

    string arrayNumCarta[] = { "As", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    int numCartaCroupier = rand() % 13; // Genera un valor entre 0 y 12
    bool esFigura = false;

        if (numCartaCroupier == 0 || (numCartaCroupier > 9 && numCartaCroupier < 13)) {

            bool esFigura = true;

            if (numCartaCroupier == 0) {

                cout << "El croupier ha obtenido un " << arrayNumCarta[0] << " de ";
                EleccionPalos();
                SaleAsCroupier();

            }
            else if (numCartaCroupier > 9 && numCartaCroupier < 13) {

                if (numCartaCroupier == 10)
                {
                    cout << "El croupier ha obtenido una " << arrayNumCarta[10] << " de ";
                    EleccionPalos();
                }
                else if (numCartaCroupier == 11)
                {
                    cout << "El croupier ha obtenido una " << arrayNumCarta[11] << " de ";
                    EleccionPalos();
                }
                else if (numCartaCroupier == 12)
                {
                    cout << "El croupier ha obtenido una " << arrayNumCarta[12] << " de ";
                    EleccionPalos();
                }
                cout << "El croupier obtiene 10 puntos \n";
                puntuacionCroupier = puntuacionCroupier + 10;
            }
        }
        else if (numCartaCroupier > 0 && numCartaCroupier < 10) {

            cout << "El croupier ha obtenido un " << (numCartaCroupier + 1) << " de ";
            EleccionPalos();
            cout << "El croupier obtiene " << numCartaCroupier + 1 << " puntos. \n";
            puntuacionCroupier = puntuacionCroupier + (numCartaCroupier + 1);

        }
        cout << "La puntuacion actual del croupier es: " << puntuacionCroupier << ".\n";
        cout << "\n";

        if (puntuacionCroupier < 21 && (puntuacionCroupier < puntuacionJugador)) {

            cout << "El croupier ha cogido otra carta.\n";
            cout << "\n";
            EleccionCartaCroupier();

        }
}

void EleccionCartaJugador() {

    string arrayNumCarta[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    int numCarta = rand() % 13; // Genera un valor entre 0 y 12
    bool esFigura = false;

    if (numCarta == 0 || (numCarta > 9 && numCarta < 13)) {

        bool esFigura = true;

        if (numCarta == 0) {

            cout << "Has obtenido un " << arrayNumCarta[0] << " de ";
            EleccionPalos();
            SaleAs();
            cout << "\n";

        }
        else if (numCarta > 9 && numCarta < 13) {

            if (numCarta == 10)
            {
                cout << "Has obtenido una " << arrayNumCarta[10] << " de ";
                EleccionPalos();
            }
            else if (numCarta == 11) 
            {    
                cout << "Has obtenido una " << arrayNumCarta[11] << " de ";
                EleccionPalos();
            }
            else if (numCarta == 12)
            {
                cout << "Has obtenido una " << arrayNumCarta[12] << " de ";
                EleccionPalos();
            }
            cout << "Obtienes 10 puntos \n";
            puntuacionJugador = puntuacionJugador + 10;
        }
    }
    else if (numCarta > 0 && numCarta < 10) {

        cout << "Has obtenido un " << (numCarta + 1) << " de ";
        EleccionPalos();
        cout << "Obtienes " << numCarta + 1 << " puntos. \n";
        puntuacionJugador = puntuacionJugador + (numCarta + 1);

    }

    if (puntuacionJugador <= 21) {
        int opcOtraCarta;
        cout << "Tu puntuacion actual es: " << puntuacionJugador << ".\n";
        cout << "\n";
        cout << "Quieres otra carta? \n";
        cout << "1 - Si | 2 - No \n";
        cin >> opcOtraCarta;
        cout << "\n";
        if (opcOtraCarta == 1) {
            EleccionCartaJugador();
        }
        else if (opcOtraCarta == 2) {
            cout << "Turno del croupier.\n";
            cout << "\n";
            EleccionCartaCroupier();
        }
        else {
            cout << "Opcion incorrecta.\n";
        }
        LogicaFin();
    }
}

int main() {

    srand(time(NULL));

    Intro();

    EleccionCartaJugador();
    
    EleccionCartaCroupier();

}