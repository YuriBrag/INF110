#include <iostream>
#include <cstdlib>
#include <thread>
#include <ctime>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
using namespace std;
using std::this_thread::sleep_for;

const float FPS = 5;
const int SCREEN_W = 420;
const int SCREEN_H = 460;
const int PILULAS_SIZE = 5;
const int PILULAS_POWER_SIZE = 10;

enum MYKEYS
{
    KEY_UP,
    KEY_DOWN,
    KEY_LEFT,
    KEY_RIGHT
};
// mapa 0 = sem parede com pilulas, 1 = parede, 2 = sem parede e sem pilula, 3 = cereja, 4 = super pilula, 5 = espaço vazio
char MAPA[23][22] =
    {
        "222222222222222222222",
        "211111111111111111112",
        "210000000010000000012",
        "214110111010111011412",
        "210000000000000000012",
        "210110101111101011012",
        "210000100010001000012",
        "211110111010111011112",
        "222210100000001012222",
        "211110101121101011112",
        "200000001222100000002",
        "211110101111101011112",
        "222210100000001012222",
        "211110101111101011112",
        "210000000010000000012",
        "210110111010111011012",
        "214010000000000010412",
        "211010101111101010112",
        "210000100010001000012",
        "210111111010111111012",
        "210000000020000000312",
        "211111111111111111112",
        "222222222222222222222",
};

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timer = NULL;
ALLEGRO_BITMAP *mapa = NULL;
ALLEGRO_BITMAP *pacmanDireita = NULL;
ALLEGRO_BITMAP *pacmanEsquerda = NULL;
ALLEGRO_BITMAP *pacmanCima = NULL;
ALLEGRO_BITMAP *pacmanBaixo = NULL;
ALLEGRO_BITMAP *fantasma1 = NULL;
ALLEGRO_BITMAP *fantasma2 = NULL;
ALLEGRO_BITMAP *fantasma3 = NULL;
ALLEGRO_BITMAP *fantasma4 = NULL;
ALLEGRO_BITMAP *fantasmaMorto = NULL;
ALLEGRO_BITMAP *fantasmaBranco = NULL;
ALLEGRO_BITMAP *pilula = NULL;
ALLEGRO_BITMAP *pilulaPower = NULL;
ALLEGRO_BITMAP *cereja = NULL;
ALLEGRO_SAMPLE *intro = NULL;
ALLEGRO_SAMPLE *morte = NULL;
ALLEGRO_SAMPLE *siren = NULL;
ALLEGRO_SAMPLE *dot = NULL;
ALLEGRO_SAMPLE *powerMode = NULL;
ALLEGRO_SAMPLE *comerFantasma = NULL;
ALLEGRO_SAMPLE *comerFruta = NULL;
ALLEGRO_FONT *fontPontuacao = NULL;
ALLEGRO_FONT *restantePower = NULL;

int i = 20, j = 10; //posicao pacman começo
int q = 20; //tamanho de cada quadrado
int fmy1 = 9, fmy2 = 10, fmy3 = 10, fmy4 = 10; // posicao y dos fantasmas na matriz
int fmx1 = 10, fmx2 = 10, fmx3 = 9, fmx4 = 11; // posicao x dos fantasmas na matriz
int posy = i * q, f1y = (fmy1 * q), f2y = (fmy2 * q), f3y = (fmy3 * q), f4y = (fmy4 * q); // posição de cada personagem pra mostrar na tela
int posx = j * q, f1x = (fmx1 * q), f2x = (fmx2 * q), f3x = (fmx3 * q), f4x = (fmx4 * q);
int pontuacao = 0, totalPilulas = 0, pontuacaoTela = 0; //cada pixel renderizado da pilula adiciona mais um em totalPilulas
int d1 = 0, d2 = 0, d3 = 0, d4 = 0; // de onde vem o fantasma, 1 = cima 2 = baixo 3 = direita 4 = esquerda, usado pra fazer com que ele não volte pro mesmo lugar
int pacman = 3; // usado pra renderizar cada imagem, virado pra cada lado. Começa com ele virado pra direita 
int dPacman = 3;
int direcaoFantasma; // resultado do rand pra onde ele vai
int tempoPower = 0; //tempo do poder, aumenta até quarenta (soma cada vez q renderiza a tela)
int contadorIntro = 0; //renderiza uma vez cont++
int f1morto = 0, f2morto = 0, f3morto = 0, f4morto = 0; // tempo do fantasma morto, renderiza uma vez cont++
int trocaFantasmaMorte = 0; //pisca fantastma(troca de 0=azul e 1=branco)

bool key[4] = {false, false, false, false}; //defalt
bool redraw = true;
bool sair = false;
bool mexerFantasmas = false; //ate a musica acabar ai vira true
bool isIntro = true; //acaba msc intro ai seta pra false
bool podeCima, podeBaixo, podeDireita, podeEsquerda; //fantasma, verifica qual lado pode ir
bool power = false; //se ta no poder
bool tocarMusica = true; //usando pra comecar a tocar msc dps da intro
bool f1alive = true, f2alive = true, f3alive = true, f4alive = true; //usando pra renderizar o fantasma se tiver vivo
bool primeiraMusica = true; //

int getDirecaoFantasma(bool podeCima, bool podeBaixo, bool podeDireita, bool podeEsquerda)
{
    int novaDirecao;

    if (!podeCima && !podeBaixo && !podeDireita && !podeEsquerda)
    {
        return 5;
    }

    if (podeCima && podeBaixo && podeDireita && podeEsquerda) // 1,2,3,4
    {
        novaDirecao = rand() % 4 + 1;
    }
    else if (podeCima && podeBaixo && podeDireita) // 1,2,3
    {
        novaDirecao = rand() % 3 + 1;
    }
    else if (podeCima && podeBaixo && podeEsquerda) // 1,2,4
    {
        novaDirecao = rand() % 4 + 1;
        while (novaDirecao == 3)//enquanto for sorteado o lado q ele veio faz de novo
        {
            novaDirecao = rand() % 4 + 1;
        }
    }
    else if (podeCima && podeDireita && podeEsquerda) // 1,3,4
    {
        novaDirecao = rand() % 4 + 1;
        while (novaDirecao == 2)
        {
            novaDirecao = rand() % 4 + 1;
        }
    }
    else if (podeBaixo && podeDireita && podeEsquerda) // 2,3,4
    {
        novaDirecao = (rand() % 3 + 1) + 1;
    }
    else if (podeCima && podeBaixo) // 1,2
    {
        novaDirecao = rand() % 2 + 1;
    }
    else if (podeCima && podeDireita) // 1,3
    {
        novaDirecao = rand() % 3 + 1;
        while (novaDirecao == 2)
        {
            novaDirecao = rand() % 3 + 1;
        }
    }
    else if (podeCima && podeEsquerda) // 1,4
    {
        novaDirecao = rand() % 4 + 1;
        while (novaDirecao == 2 || novaDirecao == 3)//so pode sortear ou 1 ou 4 por isso retira o 2 e 3
        {
            novaDirecao = rand() % 4 + 1;
        }
    }
    else if (podeBaixo && podeDireita) // 2,3
    {
        novaDirecao = (rand() % 2 + 1) + 1;
    }
    else if (podeBaixo && podeEsquerda) // 2,4
    {
        novaDirecao = (rand() % 3 + 1) + 1;
        while (novaDirecao == 3)
        {
            novaDirecao = (rand() % 3 + 1) + 1;
        }
    }
    else if (podeDireita && podeEsquerda) // 3,4
    {
        novaDirecao = (rand() % 2 + 1) + 2;
    }
    else if (podeCima)
    {
        novaDirecao = 1;
    }
    else if (podeBaixo)
    {
        novaDirecao = 2;
    }
    else if (podeDireita)
    {
        novaDirecao = 3;
    }
    else if (podeEsquerda)
    {
        novaDirecao = 4;
    }
    return novaDirecao;
}

int inicializa()
{
    al_init();

    al_init_primitives_addon();
    al_init_acodec_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_keyboard();
    al_install_audio();

    timer = al_create_timer(1.0 / FPS);

    al_reserve_samples(4);
    intro = al_load_sample("Pacman_Intro.ogg");

    morte = al_load_sample("Pacman_Death.ogg");

    siren = al_load_sample("Pacman_Siren.ogg");

    dot = al_load_sample("Pacman_Dot.ogg");

    powerMode = al_load_sample("Pacman_Power.ogg");

    comerFantasma = al_load_sample("Pacman_Ghost_Eat.ogg");

    comerFruta = al_load_sample("Pacman_Fruit.ogg");

    display = al_create_display(SCREEN_W, SCREEN_H);

    mapa = al_create_bitmap(20, 20); //dá load em tudo

    al_set_target_bitmap(mapa);
    al_clear_to_color(al_map_rgb(0, 0, 60));
    al_set_target_bitmap(al_get_backbuffer(display));

    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            if (MAPA[i][j] == '1')
            {
                al_draw_bitmap(mapa, j * q, i * q, 0);
            }
        }
    } //carrega a parede

    pacmanDireita = al_load_bitmap("pacmanDireita.tga");

    al_draw_bitmap(pacmanDireita, posx, posy, 0); //desenha o pacman no inicio

    pacmanEsquerda = al_load_bitmap("pacmanEsquerda.tga"); //quando apertado a tecla e ele puder ir dá load nisso

    pacmanCima = al_load_bitmap("pacmanCima.tga");

    pacmanBaixo = al_load_bitmap("pacmanBaixo.tga");

    fontPontuacao = al_load_font("pixelart.ttf", 15, NULL);

    restantePower = al_load_font("pixelart.ttf", 15, NULL);

    fantasma1 = al_load_bitmap("fantasma1.tga");
    if (f1alive)
        al_draw_bitmap(fantasma1, f1x, f1y, 0);

    fantasma2 = al_load_bitmap("fantasma2.tga");
    if (f2alive)
        al_draw_bitmap(fantasma2, f2x, f2y, 0);

    fantasma3 = al_load_bitmap("fantasma3.tga");
    if (f3alive)
        al_draw_bitmap(fantasma3, f3x, f3y, 0);

    fantasma4 = al_load_bitmap("fantasma4.tga");
    if (f4alive)
        al_draw_bitmap(fantasma4, f4x, f4y, 0);

    fantasmaMorto = al_load_bitmap("fantasmaMorto.tga");

    fantasmaBranco = al_load_bitmap("fantasmaBranco.tga");

    cereja = al_load_bitmap("cereja.tga");

    al_draw_textf(fontPontuacao, al_map_rgb(255, 255, 255), 90, 0, ALLEGRO_ALIGN_CENTRE, "Pontuacao  %d ", pontuacaoTela);

    for (int k = 0; k < 23; k++)
    {
        for (int p = 0; p < 22; p++)
        {
            if (MAPA[k][p] == '0')
            {
                pilula = al_create_bitmap(PILULAS_SIZE, PILULAS_SIZE);
                al_set_target_bitmap(pilula);
                al_clear_to_color(al_map_rgb(255, 255, 0));
                al_set_target_bitmap(al_get_backbuffer(display));
                al_draw_bitmap(pilula, (p * q) + 10, (k * q) + 10, 0);
                totalPilulas++;
            }
            if (MAPA[k][p] == '4')
            {
                pilulaPower = al_create_bitmap(PILULAS_POWER_SIZE, PILULAS_POWER_SIZE);
                al_set_target_bitmap(pilulaPower);
                al_clear_to_color(al_map_rgb(255, 192, 253));
                al_set_target_bitmap(al_get_backbuffer(display));
                al_draw_bitmap(pilulaPower, (p * q) + 5, (k * q) + 5, 0); //da inicio nos objetos
            }
            if (MAPA[k][p] == '3')
            {
                al_draw_bitmap(cereja, p * q, k * q, 0);
            }
        }
    }

    event_queue = al_create_event_queue();//lista de evento para renderizar

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_clear_to_color(al_map_rgb(0, 0, 0)); // preto no fundo
    al_flip_display(); //mostra a tela 
    al_start_timer(timer); //começa a renderizar a tela a cada timer

    return 1;
}

int main(int argc, char **argv)
{
    srand(time(NULL));
    if (!inicializa())
        return -1;
    al_clear_to_color(al_map_rgb(0, 0, 0));
    al_set_target_bitmap(mapa);
    al_clear_to_color(al_map_rgb(0, 0, 60));
    al_set_target_bitmap(al_get_backbuffer(display));

    for (int i = 0; i < 23; i++)
    {
        for (int j = 0; j < 22; j++)
        {
            if (MAPA[i][j] == '1')
            {
                al_draw_bitmap(mapa, j * 20, i * 20, 0);
            }
        }
    }
    al_draw_bitmap(pacmanDireita, posx, posy, 0);
    if (f1alive)
        al_draw_bitmap(fantasma1, f1x, f1y, 0);
    if (f2alive)
        al_draw_bitmap(fantasma2, f2x, f2y, 0);
    if (f3alive)
        al_draw_bitmap(fantasma3, f3x, f3y, 0);
    if (f4alive)
        al_draw_bitmap(fantasma4, f4x, f4y, 0);
    al_draw_textf(fontPontuacao, al_map_rgb(255, 255, 255), 90, 0, ALLEGRO_ALIGN_CENTRE, "Pontuacao  %d ", pontuacaoTela);
    if (power)
    {
        al_draw_textf(restantePower, al_map_rgb(255, 255, 255), 330, 0, ALLEGRO_ALIGN_CENTRE, "Tempo restante  %d ", 40 - tempoPower); //se pegar poder aonde renderiza
    }
    for (int k = 0; k < 23; k++)
    {
        for (int p = 0; p < 22; p++)
        {
            if (MAPA[k][p] == '0')
            {
                al_draw_bitmap(pilula, (p * q) + 10, (k * q) + 10, 0);
            }
            if (MAPA[k][p] == '4')
            {
                al_draw_bitmap(pilulaPower, (p * q) + 5, (k * q) + 5, 0);
            }
            if (MAPA[k][p] == '3')
            {
                al_draw_bitmap(cereja, p * q, k * q, 0);
            }
        }
    }
    al_flip_display(); //mostra
    al_play_sample(intro, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
    while (!sair)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        if (isIntro)
        {
            if (ev.type == ALLEGRO_EVENT_TIMER)
            {
                if (contadorIntro == 22)
                {
                    isIntro = false;
                }
                contadorIntro++;
            }
        }
        else
        {
            if (tocarMusica)
            {
                if (primeiraMusica)
                {
                    al_play_sample(siren, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL); //primeira musica é usado para verificar se é a primeira msc se for entra nisso uma vez e comeca a tocar sirene
                    primeiraMusica = false;
                }
                else
                {
                    al_destroy_sample(powerMode);
                    siren = al_load_sample("Pacman_Siren.ogg");
                    al_play_sample(siren, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL); //volta a tocar a sirene
                }
                tocarMusica = false; //como já ta tocando sirene em loop n entra de novo no if
            }
            if (ev.type == ALLEGRO_EVENT_TIMER)
            {
                if (!f1alive)
                {
                    if (f1morto == 20)//tempo 
                    {
                        fmy1 = 9;
                        fmx1 = 10;
                        f1y = (fmy1 * q);
                        f1x = (fmx1 * q);
                        f1alive = true;
                        f1morto = 0;
                    }
                    else
                    {
                        f1morto++; //fica somando um ao contador do fantasma morto, quando chega a 20 o fantasma tá vivo
                    }
                }
                if (!f2alive)
                {
                    if (f2morto == 20)
                    {
                        fmy2 = 10;
                        fmx2 = 10;
                        f2y = (fmy2 * q);
                        f2x = (fmx2 * q);
                        f2alive = true;
                        f2morto = 0;
                    }
                    else
                    {
                        f2morto++;
                    }
                }
                if (!f3alive)
                {
                    if (f3morto == 20)
                    {
                        fmy3 = 10;
                        fmx3 = 9;
                        f3y = (fmy3 * q);
                        f3x = (fmx3 * q);
                        f3alive = true;
                        f3morto = 0;
                    }
                    else
                    {
                        f3morto++;
                    }
                }
                if (!f4alive)
                {
                    if (f4morto == 20)
                    {
                        fmy4 = 10;
                        fmx4 = 11;
                        f4y = (fmy4 * q);
                        f4x = (fmx4 * q);
                        f4alive = true;
                        f4morto = 0;
                    }
                    else
                    {
                        f4morto++;
                    }
                }
                if (tempoPower == 40)
                {
                    power = false;
                    tocarMusica = true;
                    tempoPower = 0;
                }
                if (power)
                {
                    tempoPower++;//da mesma forma q funciona a morte do fantasma vai adicionando 1 ao contadora ate 40
                }
                if (mexerFantasmas)//so mexe a cada 2 renderizações
                {
                    mexerFantasmas = false;
                }
                else
                {
                    mexerFantasmas = true;
                }

                if (key[KEY_UP] && MAPA[i - 1][j] != '1') //ve se a posicao de cima é parede se nao for ele mnuda a direeção do pacman, muda a inteção de movimento
                {
                    pacman = 1;
                    dPacman = 1;
                }

                if (key[KEY_DOWN] && MAPA[i + 1][j] != '1')
                {
                    pacman = 2;
                    dPacman = 2;
                }

                if (key[KEY_RIGHT] && MAPA[i][j + 1] != '1')
                {
                    pacman = 3;
                    dPacman = 3;
                }

                if (key[KEY_LEFT] && MAPA[i][j - 1] != '1')
                {
                    pacman = 4;
                    dPacman = 4;
                }

                switch (dPacman)
                {
                case 1: //usado pra ele continuar andando
                    if (MAPA[i - 1][j] != '1')
                    {
                        if (MAPA[i - 1][j] == '0')
                        {
                            al_play_sample(dot, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);//ve se é pilula
                            pontuacao++;
                            pontuacaoTela += 10;
                        }
                        if (MAPA[i - 1][j] == '4')
                        {
                            al_play_sample(comerFruta, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);//ve se o lugar é pilula power
                            if (!power)
                            {
                                al_destroy_sample(siren);
                                powerMode = al_load_sample("Pacman_Power.ogg");
                                al_play_sample(powerMode, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
                            }
                            power = true;
                            tempoPower = 0;
                            pontuacaoTela += 50;
                        }
                        if (MAPA[i - 1][j] == '3')
                        {
                            al_play_sample(comerFruta, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                            pontuacaoTela += 100;
                        }
                        MAPA[i - 1][j] = '2';
                        i--;
                        posy = i * q;
                    }
                    break;
                case 2:
                    if (MAPA[i + 1][j] != '1')
                    {
                        if (MAPA[i + 1][j] == '0')
                        {
                            al_play_sample(dot, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                            pontuacao++;
                            pontuacaoTela += 10;
                        }
                        if (MAPA[i + 1][j] == '4')
                        {
                            al_play_sample(comerFruta, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                            if (!power)
                            {
                                al_destroy_sample(siren);
                                powerMode = al_load_sample("Pacman_Power.ogg");
                                al_play_sample(powerMode, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
                            }
                            power = true;
                            tempoPower = 0;
                            pontuacaoTela += 50;
                        }
                        if (MAPA[i + 1][j] == '3')
                        {
                            al_play_sample(comerFruta, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                            pontuacaoTela += 100;
                        }
                        MAPA[i + 1][j] = '2';
                        i++;
                        posy = i * q;
                    }
                    break;
                case 3:
                    if (i == 10 && j + 1 == 20) //pixel do tunel
                    {
                        if (MAPA[i][1] == '0')
                        {
                            al_play_sample(dot, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                            pontuacao++;
                            pontuacaoTela += 10;
                            MAPA[i][1] = '2';
                        }
                        j = 1;
                        posx = j * q;
                        break;
                    }
                    if (MAPA[i][j + 1] != '1')
                    {
                        if (MAPA[i][j + 1] == '0')
                        {
                            al_play_sample(dot, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                            pontuacao++;
                            pontuacaoTela += 10;
                        }
                        if (MAPA[i][j + 1] == '4')
                        {
                            al_play_sample(comerFruta, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                            if (!power)
                            {
                                al_destroy_sample(siren);
                                powerMode = al_load_sample("Pacman_Power.ogg");
                                al_play_sample(powerMode, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
                            }
                            power = true;
                            tempoPower = 0;
                            pontuacaoTela += 50;
                        }
                        if (MAPA[i][j + 1] == '3')
                        {
                            al_play_sample(comerFruta, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                            pontuacaoTela += 100;
                        }
                        MAPA[i][j + 1] = '2';
                        j++;
                        posx = j * q;
                    }
                    break;
                case 4:
                    if (i == 10 && j - 1 == 0)//pixel do tunel da esquerda
                    {
                        if (MAPA[i][19] == '0')
                        {
                            al_play_sample(dot, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                            pontuacao++;
                            pontuacaoTela += 10;
                            MAPA[i][19] = '2';
                        }
                        j = 19;
                        posx = j * q;
                        break;
                    }
                    if (MAPA[i][j - 1] != '1')
                    {
                        if (MAPA[i][j - 1] == '0')
                        {
                            al_play_sample(dot, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                            pontuacao++;
                            pontuacaoTela += 10;
                        }
                        if (MAPA[i][j - 1] == '4')
                        {
                            al_play_sample(comerFruta, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                            if (!power)
                            {
                                al_destroy_sample(siren);
                                powerMode = al_load_sample("Pacman_Power.ogg");
                                al_play_sample(powerMode, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP, NULL);
                            }
                            power = true;
                            tempoPower = 0;
                            pontuacaoTela += 50;
                        }
                        if (MAPA[i][j - 1] == '3')
                        {
                            al_play_sample(comerFruta, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                            pontuacaoTela += 100;
                        }
                        MAPA[i][j - 1] = '2';
                        j--;
                        posx = j * q;
                    }
                    break;
                }

                if (power)
                {
                    if (i == fmy1 && j == fmx1) //se bateu em algum dos fantasmas
                    {
                        al_play_sample(comerFantasma, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        pontuacaoTela += 200;
                        f1alive = false;
                    }
                    if (i == fmy2 && j == fmx2)
                    {
                        al_play_sample(comerFantasma, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        pontuacaoTela += 200;
                        f2alive = false;
                    }
                    if (i == fmy3 && j == fmx3)
                    {
                        al_play_sample(comerFantasma, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        pontuacaoTela += 200;
                        f3alive = false;
                    }
                    if (i == fmy4 && j == fmx4)
                    {
                        al_play_sample(comerFantasma, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        pontuacaoTela += 200;
                        f4alive = false;
                    }
                }
                else
                {
                    if (i == fmy1 && j == fmx1)//morte
                    {
                        al_destroy_sample(siren);
                        al_play_sample(morte, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        sleep_for(2000ms);
                        cout << "Voce perdeu..." << endl;
                        return 0;
                    }
                    if (i == fmy2 && j == fmx2)
                    {
                        al_destroy_sample(siren);
                        al_play_sample(morte, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        sleep_for(2000ms);
                        cout << "Voce perdeu..." << endl;
                        return 0;
                    }
                    if (i == fmy3 && j == fmx3)
                    {
                        al_destroy_sample(siren);
                        al_play_sample(morte, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        sleep_for(2000ms);
                        cout << "Voce perdeu..." << endl;
                        return 0;
                    }
                    if (i == fmy4 && j == fmx4)
                    {
                        al_destroy_sample(siren);
                        al_play_sample(morte, 1, 0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
                        sleep_for(2000ms);
                        cout << "Voce perdeu..." << endl;
                        return 0;
                    }
                }

                if (mexerFantasmas)//se o fantasma tiver podendo mexer
                {
                    if (f1alive)
                    {
                        podeCima = MAPA[fmy1 - 1][fmx1] != '1' && d1 != 1;//verifica pra onde o fantasma pode se direcionar
                        podeBaixo = MAPA[fmy1 + 1][fmx1] != '1' && d1 != 2;
                        podeDireita = MAPA[fmy1][fmx1 + 1] != '1' && d1 != 3;
                        podeEsquerda = MAPA[fmy1][fmx1 - 1] != '1' && d1 != 4;
                        direcaoFantasma = getDirecaoFantasma(podeCima, podeBaixo, podeDireita, podeEsquerda); //funcao que sorteia os caminhos
                        if (direcaoFantasma == 1)
                        {
                            fmy1--;
                            d1 = 2;
                            f1y = (fmy1 * q);
                        }
                        else if (direcaoFantasma == 2)
                        {
                            fmy1++;
                            d1 = 1;
                            f1y = (fmy1 * q);
                        }
                        else if (direcaoFantasma == 3)
                        {
                            if (fmy1 == 10 && fmx1 + 1 == 20)
                            {
                                fmx1 = 1;
                                d1 = 4;
                                f1x = fmx1 * q;
                            }
                            else
                            {
                                fmx1++;
                                d1 = 4;
                                f1x = (fmx1 * q);
                            }
                        }
                        else if (direcaoFantasma == 4)
                        {
                            if (fmy1 == 10 && fmx1 - 1 == 0)
                            {
                                fmx1 = 19;
                                d1 = 3;
                                f1x = fmx1 * q;
                            }
                            else
                            {
                                fmx1--;
                                d1 = 3;
                                f1x = (fmx1 * q);
                            }
                        }
                        else if (direcaoFantasma == 5)
                        {
                            if (MAPA[fmy1 - 1][fmx1] != '1' && d1 == 1)
                            {
                                fmy1--;
                                d1 = 2;
                                f1y = (fmy1 * q);
                            }
                            else if (MAPA[fmy1 + 1][fmx1] != '1' && d1 == 2)
                            {
                                fmy1++;
                                d1 = 1;
                                f1y = (fmy1 * q);
                            }
                            else if (MAPA[fmy1][fmx1 + 1] != '1' && d1 == 3)
                            {
                                fmx1++;
                                d1 = 4;
                                f1x = (fmx1 * q);
                            }
                            else if (MAPA[fmy1][fmx1 - 1] != '1' && d1 == 4)
                            {
                                fmx1--;
                                d1 = 3;
                                f1x = (fmx1 * q);
                            }
                        }
                    }
                    if (f2alive)
                    {
                        podeCima = MAPA[fmy2 - 1][fmx2] != '1' && d2 != 1;
                        podeBaixo = MAPA[fmy2 + 1][fmx2] != '1' && d2 != 2;
                        podeDireita = MAPA[fmy2][fmx2 + 1] != '1' && d2 != 3;
                        podeEsquerda = MAPA[fmy2][fmx2 - 1] != '1' && d2 != 4;
                        direcaoFantasma = getDirecaoFantasma(podeCima, podeBaixo, podeDireita, podeEsquerda);
                        if (direcaoFantasma == 1)
                        {
                            fmy2--;
                            d2 = 2;
                            f2y = (fmy2 * q);
                        }
                        else if (direcaoFantasma == 2)
                        {
                            fmy2++;
                            d2 = 1;
                            f2y = (fmy2 * q);
                        }
                        else if (direcaoFantasma == 3)
                        {
                            if (fmy2 == 10 && fmx2 + 1 == 20)
                            {
                                fmx2 = 1;
                                d2 = 4;
                                f2x = fmx2 * q;
                            }
                            else
                            {
                                fmx2++;
                                d2 = 4;
                                f2x = (fmx2 * q);
                            }
                        }
                        else if (direcaoFantasma == 4)
                        {
                            if (fmy2 == 10 && fmx2 - 1 == 0)
                            {
                                fmx2 = 19;
                                d2 = 3;
                                f2x = fmx2 * q;
                            }
                            else
                            {
                                fmx2--;
                                d2 = 3;
                                f2x = (fmx2 * q);
                            }
                        }
                        else if (direcaoFantasma == 5)
                        {
                            if (MAPA[fmy2 - 1][fmx2] != '1' && d2 == 1)
                            {
                                fmy2--;
                                d2 = 2;
                                f2y = (fmy2 * q);
                            }
                            else if (MAPA[fmy2 + 1][fmx2] != '1' && d2 == 2)
                            {
                                fmy2++;
                                d2 = 1;
                                f2y = (fmy2 * q);
                            }
                            else if (MAPA[fmy2][fmx2 + 1] != '1' && d2 == 3)
                            {
                                fmx2++;
                                d2 = 4;
                                f2x = (fmx2 * q);
                            }
                            else if (MAPA[fmy2][fmx2 - 1] != '1' && d2 == 4)
                            {
                                fmx2--;
                                d2 = 3;
                                f2x = (fmx2 * q);
                            }
                        }
                    }
                    if (f3alive)
                    {
                        podeCima = MAPA[fmy3 - 1][fmx3] != '1' && d3 != 1;
                        podeBaixo = MAPA[fmy3 + 1][fmx3] != '1' && d3 != 2;
                        podeDireita = MAPA[fmy3][fmx3 + 1] != '1' && d3 != 3;
                        podeEsquerda = MAPA[fmy3][fmx3 - 1] != '1' && d3 != 4;
                        direcaoFantasma = getDirecaoFantasma(podeCima, podeBaixo, podeDireita, podeEsquerda);
                        if (direcaoFantasma == 1)
                        {
                            fmy3--;
                            d3 = 2;
                            f3y = (fmy3 * q);
                        }
                        else if (direcaoFantasma == 2)
                        {
                            fmy3++;
                            d3 = 1;
                            f3y = (fmy3 * q);
                        }
                        else if (direcaoFantasma == 3)
                        {
                            if (fmy3 == 10 && fmx3 + 1 == 20)
                            {
                                fmx3 = 1;
                                d3 = 4;
                                f3x = fmx3 * q;
                            }
                            else
                            {
                                fmx3++;
                                d3 = 4;
                                f3x = (fmx3 * q);
                            }
                        }
                        else if (direcaoFantasma == 4)
                        {
                            if (fmy3 == 10 && fmx3 - 1 == 0)
                            {
                                fmx3 = 19;
                                d3 = 3;
                                f3x = fmx3 * q;
                            }
                            else
                            {
                                fmx3--;
                                d3 = 3;
                                f3x = (fmx3 * q);
                            }
                        }
                        else if (direcaoFantasma == 5)
                        {
                            if (MAPA[fmy3 - 1][fmx3] != '1' && d3 == 1)
                            {
                                fmy3--;
                                d3 = 2;
                                f3y = (fmy3 * q);
                            }
                            else if (MAPA[fmy3 + 1][fmx3] != '1' && d3 == 2)
                            {
                                fmy3++;
                                d3 = 1;
                                f3y = (fmy3 * q);
                            }
                            else if (MAPA[fmy3][fmx3 + 1] != '1' && d3 == 3)
                            {
                                fmx3++;
                                d3 = 4;
                                f3x = (fmx3 * q);
                            }
                            else if (MAPA[fmy3][fmx3 - 1] != '1' && d3 == 4)
                            {
                                fmx3--;
                                d3 = 3;
                                f3x = (fmx3 * q);
                            }
                        }
                    }
                    if (f4alive)
                    {
                        podeCima = MAPA[fmy4 - 1][fmx4] != '1' && d4 != 1;
                        podeBaixo = MAPA[fmy4 + 1][fmx4] != '1' && d4 != 2;
                        podeDireita = MAPA[fmy4][fmx4 + 1] != '1' && d4 != 3;
                        podeEsquerda = MAPA[fmy4][fmx4 - 1] != '1' && d4 != 4;
                        direcaoFantasma = getDirecaoFantasma(podeCima, podeBaixo, podeDireita, podeEsquerda);
                        if (direcaoFantasma == 1)
                        {
                            fmy4--;
                            d4 = 2;
                            f4y = (fmy4 * q);
                        }
                        else if (direcaoFantasma == 2)//aumenta um na posi fantasma da matriz
                        {
                            fmy4++;
                            d4 = 1;
                            f4y = (fmy4 * q);
                        }
                        else if (direcaoFantasma == 3)
                        {
                            if (fmy4 == 10 && fmx4 + 1 == 20)//tunel
                            {
                                fmx4 = 1;
                                d4 = 4;
                                f4x = fmx4 * q;
                            }
                            else
                            {
                                fmx4++;
                                d4 = 4;
                                f4x = (fmx4 * q);
                            }
                        }
                        else if (direcaoFantasma == 4)
                        {
                            if (fmy4 == 10 && fmx4 - 1 == 0)
                            {
                                fmx4 = 19;
                                d4 = 3;
                                f4x = fmx4 * q;
                            }
                            else
                            {
                                fmx4--;
                                d4 = 3;
                                f4x = (fmx4 * q);
                            }
                        }
                        else if (direcaoFantasma == 5)
                        {
                            if (MAPA[fmy4 - 1][fmx4] != '1' && d4 == 1)//valida a posição de sem saida
                            {
                                fmy4--;
                                d4 = 2;
                                f4y = (fmy4 * q);
                            }
                            else if (MAPA[fmy4 + 1][fmx4] != '1' && d4 == 2)
                            {
                                fmy4++;
                                d4 = 1;
                                f4y = (fmy4 * q);
                            }
                            else if (MAPA[fmy4][fmx4 + 1] != '1' && d4 == 3)
                            {
                                fmx4++;
                                d4 = 4;
                                f4x = (fmx4 * q);
                            }
                            else if (MAPA[fmy4][fmx4 - 1] != '1' && d4 == 4)
                            {
                                fmx4--;
                                d4 = 3;
                                f4x = (fmx4 * q);
                            }
                        }
                    }
                }
                redraw = true;
            }
            else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            {
                break;
            }
            else if (ev.type == ALLEGRO_EVENT_KEY_DOWN)//evento de tecla pra baixo
            {
                switch (ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_UP:
                    key[KEY_UP] = true;
                    break;

                case ALLEGRO_KEY_DOWN:
                    key[KEY_DOWN] = true;
                    break;

                case ALLEGRO_KEY_LEFT:
                    key[KEY_LEFT] = true;
                    break;

                case ALLEGRO_KEY_RIGHT:
                    key[KEY_RIGHT] = true;
                    break;
                }
            }
            else if (ev.type == ALLEGRO_EVENT_KEY_UP)
            {
                switch (ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_UP:
                    key[KEY_UP] = false;
                    break;

                case ALLEGRO_KEY_DOWN:
                    key[KEY_DOWN] = false;
                    break;

                case ALLEGRO_KEY_LEFT:
                    key[KEY_LEFT] = false;
                    break;

                case ALLEGRO_KEY_RIGHT:
                    key[KEY_RIGHT] = false;
                    break;

                case ALLEGRO_KEY_ESCAPE:
                    sair = true;
                    break;
                }
            }
        }

        if (redraw && al_is_event_queue_empty(event_queue))
        {
            redraw = false;

            al_clear_to_color(al_map_rgb(0, 0, 0));

            al_set_target_bitmap(mapa);
            al_clear_to_color(al_map_rgb(0, 0, 60));
            al_set_target_bitmap(al_get_backbuffer(display));

            for (int i = 0; i < 23; i++)
            {
                for (int j = 0; j < 22; j++)
                {
                    if (MAPA[i][j] == '1')
                    {
                        al_draw_bitmap(mapa, j * q, i * q, 0);
                    }
                }
            }
            if (power)
            {
                if (tempoPower >= 30)
                {
                    if (trocaFantasmaMorte == 0)
                    {
                        if (f1alive)
                            al_draw_bitmap(fantasmaBranco, f1x, f1y, 0);
                        if (f2alive)
                            al_draw_bitmap(fantasmaBranco, f2x, f2y, 0);
                        if (f3alive)
                            al_draw_bitmap(fantasmaBranco, f3x, f3y, 0);
                        if (f4alive)
                            al_draw_bitmap(fantasmaBranco, f4x, f4y, 0);
                        trocaFantasmaMorte = 1;
                    }
                    else
                    {
                        if (f1alive)
                            al_draw_bitmap(fantasmaMorto, f1x, f1y, 0);
                        if (f2alive)
                            al_draw_bitmap(fantasmaMorto, f2x, f2y, 0);
                        if (f3alive)
                            al_draw_bitmap(fantasmaMorto, f3x, f3y, 0);
                        if (f4alive)
                            al_draw_bitmap(fantasmaMorto, f4x, f4y, 0);
                        trocaFantasmaMorte = 0;
                    }
                }
                else
                {
                    if (f1alive)
                        al_draw_bitmap(fantasmaMorto, f1x, f1y, 0);
                    if (f2alive)
                        al_draw_bitmap(fantasmaMorto, f2x, f2y, 0);
                    if (f3alive)
                        al_draw_bitmap(fantasmaMorto, f3x, f3y, 0);
                    if (f4alive)
                        al_draw_bitmap(fantasmaMorto, f4x, f4y, 0);
                }
            }
            else
            {
                if (f1alive)
                    al_draw_bitmap(fantasma1, f1x, f1y, 0);
                if (f2alive)
                    al_draw_bitmap(fantasma2, f2x, f2y, 0);
                if (f3alive)
                    al_draw_bitmap(fantasma3, f3x, f3y, 0);
                if (f4alive)
                    al_draw_bitmap(fantasma4, f4x, f4y, 0);
            }
            al_draw_textf(fontPontuacao, al_map_rgb(255, 255, 255), 90, 0, ALLEGRO_ALIGN_CENTRE, "Pontuacao  %d ", pontuacaoTela);
            if (power)
            {
                al_draw_textf(restantePower, al_map_rgb(255, 255, 255), 330, 0, ALLEGRO_ALIGN_CENTRE, "Tempo restante  %d ", 40 - tempoPower);
            }
            switch (pacman)
            {
            case 1:
                al_draw_bitmap(pacmanCima, posx, posy, 0);
                break;
            case 2:
                al_draw_bitmap(pacmanBaixo, posx, posy, 0);
                break;
            case 3:
                al_draw_bitmap(pacmanDireita, posx, posy, 0);
                break;
            case 4:
                al_draw_bitmap(pacmanEsquerda, posx, posy, 0);
                break;
            }
            for (int k = 0; k < 23; k++)
            {
                for (int p = 0; p < 22; p++)
                {
                    // ve onde n tem fantasma pra renderizar pilula, se não fica fantasma em cima da pilula
                    bool temFantasma = false;
                    if (k == fmy1 && p == fmx1)
                        temFantasma = true;
                    if (k == fmy2 && p == fmx2)
                        temFantasma = true;
                    if (k == fmy3 && p == fmx3)
                        temFantasma = true;
                    if (k == fmy4 && p == fmx4)
                        temFantasma = true;
                    if (MAPA[k][p] == '0' && !temFantasma)
                        al_draw_bitmap(pilula, (p * q) + 10, (k * q) + 10, 0);
                    if (MAPA[k][p] == '4' && !temFantasma)
                        al_draw_bitmap(pilulaPower, (p * q) + 5, (k * q) + 5, 0);
                    if (MAPA[k][p] == '3' && !temFantasma)
                        al_draw_bitmap(cereja, (p * q), (k * q), 0);
                }
            }
            al_flip_display();
        }
        if (pontuacao == totalPilulas)//jogo acaba
        {
            cout << "Parabens voce ganhou!" << endl;
            return 0;
        }
    }

    al_destroy_sample(intro);
    al_destroy_sample(morte);
    al_destroy_sample(siren);
    al_destroy_sample(dot);
    al_destroy_bitmap(mapa);
    al_destroy_bitmap(pacmanDireita);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}