#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "automato.h"

// Define o tamanho de cada célula na visualização
#define CELL_SIZE 10

// Define o número de quadros por segundo para a animação
#define FPS 1

// Função para desenhar o reticulado grade do autômato celular
void desenharReticulado(AutomatoCelular *automato)
{
    int ordem = automato->ordem; // Obtém a ordem (dimensao) do reticulado
    for (int i = 0; i < ordem; i++)
    {
        for (int j = 0; j < ordem; j++)
        {
            // Desenha uma célula viva como um retângulo branco
            if (automato->matriz[i][j] == 1)
            {
                al_draw_filled_rectangle(j * CELL_SIZE, i * CELL_SIZE,
                                         (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE,
                                         al_map_rgb(255, 255, 255));
                // Desenha uma célula morta como um retângulo preto
            }
            else
            {
                al_draw_filled_rectangle(j * CELL_SIZE, i * CELL_SIZE,
                                         (j + 1) * CELL_SIZE, (i + 1) * CELL_SIZE,
                                         al_map_rgb(0, 0, 0));
            }
        }
    }
}

int main()
{
    int ordem, geracoes;
    // Lê a ordem do reticulado e o número de gerações a partir da entrada padrão
    scanf("%d %d", &ordem, &geracoes);

    // Inicializa o autômato celular a partir da entrada
    AutomatoCelular *automato = leituraReticulado(ordem);

    // Inicializa a biblioteca Allegro
    if (!al_init())
    {
        fprintf(stderr, "Falha ao inicializar o Allegro.\n");
        desalocarReticulado(automato);
        return -1;
    }

    // Inicializa o addon de primitivas do Allegro (necessário para desenhar formas)
    if (!al_init_primitives_addon())
    {
        fprintf(stderr, "Falha ao inicializar addons de primitivas.\n");
        desalocarReticulado(automato);
        return -1;
    }

    // Cria uma janela de exibição com as dimensões apropriadas
    ALLEGRO_DISPLAY *display = al_create_display(ordem * CELL_SIZE, ordem * CELL_SIZE);
    if (!display)
    {
        fprintf(stderr, "Falha ao criar display.\n");
        al_shutdown_primitives_addon();
        desalocarReticulado(automato);
        return -1;
    }

    // Define o título da janela
    al_set_window_title(display, "Jogo da Vida");

    // Cria um timer que irá disparar eventos a cada 1/FPS segundos
    ALLEGRO_TIMER *timer = al_create_timer(1.0 / FPS);
    if (!timer)
    {
        fprintf(stderr, "Falha ao criar timer.\n");
        al_destroy_display(display);
        al_shutdown_primitives_addon();
        desalocarReticulado(automato);
        return -1;
    }

    // Cria uma fila de eventos para capturar eventos do Allegro
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    if (!event_queue)
    {
        fprintf(stderr, "Falha ao criar fila de eventos.\n");
        al_destroy_timer(timer);
        al_destroy_display(display);
        al_shutdown_primitives_addon();
        desalocarReticulado(automato);
        return -1;
    }

    // Registra as fontes de eventos para a fila de eventos
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    // Inicia o timer
    al_start_timer(timer);

    int frame = 0; // Contador de gerações processadas
    // Loop principal para processar eventos e atualizar a exibição
    while (frame < geracoes)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        // Verifica se o evento é do tipo timer (atualização da geração)
        if (ev.type == ALLEGRO_EVENT_TIMER)
        {
            al_clear_to_color(al_map_rgb(0, 0, 0)); // Limpa a tela com a cor preta
            evoluirReticulado(automato, 1);         // Evolui o autômato para a próxima geração
            desenharReticulado(automato);           // Desenha o estado atual do reticulado
            al_flip_display();                      // Atualiza a tela
            frame++;                                // Incrementa o contador de gerações
            // Verifica se o evento é de fechamento da janela
        }
        else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break; // Sai do loop principal
        }
    }

    // Desaloca todos os recursos do Allegro e do autômato celular
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_destroy_display(display);
    al_shutdown_primitives_addon();
    desalocarReticulado(automato);

    return 0;
}