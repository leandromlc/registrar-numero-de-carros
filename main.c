#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Week
{
    char name[7];
    bool peak_day;
    int total_cars;
};

int main()
{
    const char default_data[7][20] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};

    struct Week week[7];

    for (int i = 0; i < 7; i++)
    {
        week[i].total_cars = 0;
        week[i].peak_day = false;
        strcpy(week[i].name, default_data[i]);
    }

    while (true)
    {
        printf("\n--- Sistema de Cadastro de Fluxo de Veiculos ---\n");

        printf("\n1. Atualizar total de carros\n");
        printf("2. Listar dias da semana\n");
        printf("3. Listar todos os registros\n");
        printf("4. Sair\n");

        char option;

        printf("\nEscolha uma opção: ");
        scanf(" %c", &option);

        switch (option)
        {

        case '1':
            char day[7];
            int total_cars;

            while (true)
            {
                bool day_exists = false;

                printf("Digite o nome do dia (ex: Segunda, Terça, etc.): ");
                int day_field = scanf("%s", &day);

                for (int i = 0; i < 7; i++)
                {
                    if (strcmp(default_data[i], day) == 0)
                    {
                        day_exists = true;
                    }
                }

                if (day_field != 1 || !day_exists)
                {
                    printf("\nERRO: Entrada inválida! Por favor, liste as opções disponíveis na opção 2 do menu.\n\n");

                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                }
                else
                {
                    break;
                }
            }

            while (true)
            {
                printf("Digite a quantidade de carros (ex: 3): ");
                int total_cars_field = scanf("%d", &total_cars);

                if (total_cars_field != 1 || total_cars < 0)
                {
                    printf("\nERRO: Entrada inválida! Por favor, digite apenas números.\n\n");

                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                }
                else
                {
                    break;
                }
            }

            int greater_flow, peak_day_index;
            greater_flow = week[0].total_cars;

            for (int i = 0; i < 7; i++)
            {
                week[i].peak_day = false;

                if (strcmp(week[i].name, day) == 0)
                {
                    printf("%d", total_cars);
                    week[i].total_cars = week[i].total_cars + total_cars;
                }

                if (week[i].total_cars > greater_flow)
                {
                    greater_flow = week[i].total_cars;
                    peak_day_index = i;
                }
            }
            week[peak_day_index].peak_day = true;

            printf("\nOs registros foram gravados!\n");

            break;

        case '2':
            printf("\n--- Opções de dias da semana: ---\n\n");

            for (int i = 0; i < 7; i++)
            {
                printf("- %s \n", default_data[i]);
            }
            break;

        case '3':
            for (int i = 0; i < 7; i++)
            {
                if (week[i].peak_day)
                {
                    printf("\nDia de pico");
                }

                printf("\nDia da semana: %s\n", week[i].name);
                printf("Total de carros registrados: %d\n", week[i].total_cars);
            }
            break;

        case '4':
            printf("\nSaindo da aplicação...\n");
            return 0;

        default:
            printf("\n\nOpção inválida. Por favor, tente novamente.\n");
            break;
        }
    }

    return 0;
}
