#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

float FullHealth;
float FullPlayerHealth;

typedef struct stats{
    float hp;
    int atk;
    int def;
    int speed;
    int level;     
    int exp;
    int expLimit;
    char rarity[30];
    char nome[30];
    char equipamento[200];

}Stats;

Stats generateEnemy(Stats player);
char *RandomNames(Stats enemy);
void PrintEnemy(Stats *enemy);
Stats FullEnemy(Stats player);
Stats createPlayer();
void PrintPlayer(Stats *player);
bool Fight(Stats *player, Stats *enemy);
void PlayerModifier(Stats *player);


 Stats generateEnemy(Stats player){

    srand(time(NULL));

    int inferior = player.level;
    int superior = player.level + 4;

    int enemyLevel = (rand() % (superior - inferior + 1)) + inferior;

    Stats enemy;
    int rarity = (rand() % (100 - 0 + 1) + 0);
    if (rarity < 50){
        strcpy(enemy.rarity, "comum");
        enemy.level = enemyLevel;
        enemy.atk = (rand() % ((enemyLevel * 2) - enemyLevel)) + enemyLevel;
        enemy.hp = (rand() % ((enemyLevel * 10) - (enemyLevel * 5))) + enemyLevel * 5;
        enemy.def = (rand() % (enemyLevel - (enemyLevel / 2))) + enemyLevel / 2;
        enemy.speed = (rand() % ((enemyLevel) - (enemyLevel / 2))) + enemyLevel / 2;
        enemy.exp = 1.4 * (rand() % ((enemyLevel * 10) - (enemyLevel * 5))) + enemyLevel * 5;
        return enemy;

    }
    if (rarity > 50 && rarity < 70) {
        strcpy(enemy.rarity, "raro");
        enemy.level = enemyLevel;
        enemy.atk = 1.2 * (rand() % ((enemyLevel * 2) - enemyLevel)) + enemyLevel;
        enemy.hp = 1.2 * (rand() % ((enemyLevel * 10) - (enemyLevel * 5))) + enemyLevel * 5;
        enemy.def = 1.2 * (rand() % (enemyLevel - (enemyLevel / 2))) + enemyLevel / 2;
        enemy.speed = 1.2 * (rand() % ((enemyLevel) - (enemyLevel / 2))) + enemyLevel / 2;
        enemy.exp = 2 * (rand() % ((enemyLevel * 10) - (enemyLevel * 5))) + enemyLevel * 5;
        return enemy;
    }
    if (rarity > 70 && rarity < 80){
        strcpy(enemy.rarity, "epico");
        enemy.level = enemyLevel;
        enemy.atk = 1.4 * (rand() % ((enemyLevel * 2) - enemyLevel)) + enemyLevel;
        enemy.hp = 1.4 * (rand() % ((enemyLevel * 10) - (enemyLevel * 5))) + enemyLevel * 5;
        enemy.def = 1.4 * (rand() % (enemyLevel - (enemyLevel / 2))) + enemyLevel / 2;
        enemy.speed = 1.4 * (rand() % ((enemyLevel) - (enemyLevel / 2))) + enemyLevel / 2;
        enemy.exp = 3 * (rand() % ((enemyLevel * 10) - (enemyLevel * 5))) + enemyLevel * 5;
        return enemy;
    }
    if (rarity > 80 && rarity < 88) {
        strcpy(enemy.rarity, "lendario");
        enemy.level = enemyLevel;
        enemy.atk = 2 * (rand() % ((enemyLevel * 2) - enemyLevel)) + enemyLevel;
        enemy.hp = 2 * (rand() % ((enemyLevel * 10) - (enemyLevel * 5))) + enemyLevel * 5;
        enemy.def = 2 * (rand() % (enemyLevel - (enemyLevel / 2))) + enemyLevel / 2;
        enemy.speed = 2 * (rand() % ((enemyLevel) - (enemyLevel / 2))) + enemyLevel / 2;
        enemy.exp = 5 * (rand() % ((enemyLevel * 10) - (enemyLevel * 5))) + enemyLevel * 5;
        return enemy;
    }
    if (rarity > 88 && rarity < 95){
        strcpy(enemy.rarity, "especial");
        enemy.level = enemyLevel;
        enemy.atk = 3 * (rand() % ((enemyLevel * 2) - enemyLevel)) + enemyLevel;
        enemy.hp = 3 * (rand() % ((enemyLevel * 10) - (enemyLevel * 5))) + enemyLevel * 5;
        enemy.def = 3 * (rand() % (enemyLevel - (enemyLevel / 2))) + enemyLevel / 2;
        enemy.speed = 3 * (rand() % ((enemyLevel) - (enemyLevel / 2))) + enemyLevel / 2;
        enemy.exp = 10 * (rand() % ((enemyLevel * 10) - (enemyLevel * 5))) + enemyLevel * 5;
        return enemy;
    }
    if (rarity > 95) {
        strcpy(enemy.rarity, "???");
        enemy.level = enemyLevel;
        enemy.atk = 5 * (rand() % ((enemyLevel * 2) - enemyLevel)) + enemyLevel;
        enemy.hp = 5 * (rand() % ((enemyLevel * 10) - (enemyLevel * 5))) + enemyLevel * 5;
        enemy.def = 5 * (rand() % (enemyLevel - (enemyLevel / 2))) + enemyLevel / 2;
        enemy.speed = 5 * (rand() % ((enemyLevel) - (enemyLevel / 2))) + enemyLevel / 2;
        enemy.exp = 20 * (rand() % ((enemyLevel * 10) - (enemyLevel * 5))) + enemyLevel * 5;
        return enemy;
    }
    
    return enemy;

 }

char *RandomNames(Stats enemy){

    char *nomesComum[MAX] = {"Orc", "Goblin", "Esqueleto", "Zumbi", "Morcego Gigante", "Aranha venenosa", "Rato monstruoso", "Lobo Sombrio", "Guerreiro Sombrio", "Bandido"};
    char *nomesEpico[MAX] = {"Fungoid Aberration", "Ironclad Automaton", "Vicious Gnoll", "Harpy Queen", "Darkling Assassin", "Giant Scorpion", "Chimeric Beast", "BloodThirsty Vampire", "Sea Serpent", "Thunderous Golem"};
    char *nomesRaro[MAX] = {"Orc king", "Goblin Automaton", "Esqueleto Selvagem", "Descending Zombie", "Plague Doctor", "Shadow Stalker", "Dark Paladin", "ThunderBird", "Plague exterminator", "Sick Vampire"};
    char *nomesLendarios[MAX] = {"Vorgoth, O destruidor de mundos", "Morgoth, o Senhor do Abismo", "Zoltar, o Bruxo Sombrio", "Xarathos, o Devorador de Almas", "Gorgon, o Basilisco Negro", "Drakonis, o Dragão de Fogo", "Malphas, o Demônio da Noite", "Kethos, o Lorde do Caos", "Surtur, o Gigante de Fogo", "The Elden Lord"};
    char *nomesBoss[MAX] = {"Abaddon - o destruidor", "Asmodeus - The fallen God", "Beelzebub - o senhor das moscas", "Belial - o sem mestre", "Leviatã - o dragão das profundezas", "Lúcifer - o portador da luz", "Mammon - o deus da riqueza", "Moloch - o devorador", "Nergal - o deus da peste e da morte.", "Azazel, o Anjo Caído da Perdição"};

    srand(time(NULL));

    int indice_nome = rand() % MAX;

    if (strcmp(enemy.rarity, "comum") == 0) {
        return nomesComum[indice_nome];
    }
    if (strcmp(enemy.rarity, "raro") == 0) {
        return nomesRaro[indice_nome];
    }
    if (strcmp(enemy.rarity, "epico") == 0) {
        return nomesEpico[indice_nome];
    }
    if (strcmp(enemy.rarity, "lendario") == 0) {
        return nomesLendarios[indice_nome];
    }
    if(strcmp(enemy.rarity, "boss") == 0) {
        return nomesBoss[indice_nome];
    }
    return nomesComum[indice_nome];
}

void PrintEnemy(Stats *enemy){


    printf("\n---%s[%d]--- ( %s )", enemy->nome, enemy->level, enemy->rarity);
    printf("\nHP - %.2f/%.2f", enemy->hp, FullHealth);
    printf("\nATK - %d", enemy->atk);
    printf("\nDEF - %d", enemy->def);
    printf("\nSPEED - %d", enemy->speed);
}

Stats FullEnemy(Stats player){

    Stats enemy;

    enemy = generateEnemy(player);
    strcpy(enemy.nome,RandomNames(enemy));
    FullHealth = enemy.hp;

    return enemy;
    

}

Stats createPlayer(){

    float hp;
    int atk, def, speed;
    char nome[100];

    printf("Digite o hp: ");
    scanf("%f", &hp);
    printf("Digite o atk: ");
    scanf("%d", &atk);
    printf("Digite a def: ");
    scanf("%d", &def);
    printf("Digite a speed: ");
    scanf("%d", &speed);
    printf("Digite o nome: ");
    scanf("%[^\n]s", nome);
    

    Stats player;

    player.hp = hp;
    player.atk = atk;
    player.def = def;
    player.speed = speed;
    player.expLimit = 100;
    FullPlayerHealth = player.hp;
    player.level = 1;
    strcpy(player.nome , nome);

    return player;

}

void PrintPlayer(Stats *player){

    printf("\n---PLAYER--- ( %d ) // exp: [%d/%d]", player->level, player->exp, player->expLimit);
    printf("\nHP - %.2f/%.2f", player->hp, FullPlayerHealth);
    printf("\nATK - %d", player->atk);
    printf("\nDEF - %d", player->def);
    printf("\nSPEED - %d", player->speed);
    printf("\n\nEquipamentos: %s", player->equipamento);
}

void levelUp(Stats **player){

    int exp = (*player)->exp - (*player)->expLimit;
    (*player)->expLimit *= 1.5;
    (*player)->level += 1;
    (*player)->exp = exp;

    FullPlayerHealth += 10;
    (*player)->hp += 10;
    (*player)->atk += 3;
    (*player)->def += 1;
    (*player)->speed += 1;
}



bool Fight(Stats *player, Stats *enemy){

    srand(time(NULL));
    bool PlayerTurn;
    

    if (player->speed > enemy->speed){
        PlayerTurn = true;
    } else {
        PlayerTurn = false;
    }
    while (enemy->hp > 0 || player->hp > 0) {
    if (PlayerTurn == true) {
        int escolha;
        printf("\n--TURNO DO JOGADOR--");
        printf("\n\n1. Atacar");
        printf("\n2. Passar vez");
        printf("\n3. Fugir");
        printf("\nEscolha: ");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
            int Dmg = (rand() % ((player->atk + 2 ) - (player->atk)) + player->atk);
            enemy->hp -= Dmg;
            printf("\nDmg: %d", Dmg);
            printf("\n");
            PrintEnemy(enemy);
            if (enemy->hp <= 0){
                printf("\nINIMIGO DERROTADO");
                printf("\nEXP: %d", enemy->exp);
                player->exp += enemy->exp;

            if (player->exp >= player->expLimit) {
                levelUp(&player);
                printf("\nLEVEL UP");
            }
            return true;
            }
            break;

            case 2:
            PlayerTurn = false;
            break;

            case 3:
            
            int num = rand() % 1;
            if (num == 1){
                PlayerTurn = false;
            }
            break;

        }
        PlayerTurn = false;
    }
    if (PlayerTurn == false) {
        int escolha;
        printf("\n--TURNO DO INIMIGO--");
        printf("\n\n1. Atacar");
        printf("\n2. Passar vez");
        printf("\n3. Fugir");
        printf("\nEscolha: ");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
            int Dmg = (rand() % ((enemy->atk + 2 ) - (enemy->atk)) + enemy->atk);
            player->hp -= Dmg;
            printf("\nDmg: %d", Dmg);
            printf("\n");
            PrintPlayer(player);
            if (player->hp <= 0){
                printf("\nO JOGADOR MORREU");
            return false;
            }
            break;

            case 2:
            PlayerTurn = false;
            break;

            case 3:
            int num = rand() % 1;
            if (num == 1){
                PlayerTurn = true;
            }
            break;

        }

        PlayerTurn = true;

    }

    }
    if (player->hp == 0){
        printf("\nO JOGADOR MORREU");
        return false;
    }
    if (enemy->hp == 0){
        printf("\nINIMIGO DERROTADO");
        printf("\nEXP: %d", enemy->exp);
        player->exp += enemy->exp;

        if (player->exp >= player->expLimit) {
            levelUp(&player);
            printf("\nLEVEL UP");
        }
        return true;
        
    }
    return false;
}

void PlayerModifier(Stats *player){

    char escolha[10];
    int valor;

    printf("Qual atributo deseja modificar ?");
    scanf("%s", escolha);

    if (strcmp(escolha, "atk") == 0 ) {    
        printf("Digite o novo valor: ");
        scanf("%d", &valor);
        player->atk = valor;
    } if (strcmp(escolha, "def") == 0){
        printf("Digite o novo valor: ");
        scanf("%d", &valor);
        player->def = valor;
    }if (strcmp(escolha, "speed") == 0){
        printf("Digite o novo valor: ");
        scanf("%d", &valor);
        player->speed = valor;
    }if (strcmp(escolha, "hp") == 0){
        printf("Digite o novo valor: ");
        scanf("%d", &valor);
        player->hp = valor;
    }
}

void Equipament(Stats *player){

    char equipamento[100];
    char tipo[10];
    int buff;
    char separator[2] = "-";
    char separator1[2] = "\n";

    printf("Digite o equipamento: ");
    scanf(" %[^\n]s", equipamento);
    strcat(player->equipamento, equipamento);
    strcat(player->equipamento, separator1);
    printf("Digite o tipo de buff: ");
    scanf("%s", tipo);
    strcat(player->equipamento, separator);
    strcat(player->equipamento, tipo);
    printf("Digite o buff: ");
    scanf("%d", &buff);
        if (strcmp(tipo, "atk") == 0){
            player->atk += buff;
        }
        if (strcmp(tipo, "def") == 0){
            player->def += buff;
        }
        if (strcmp(tipo, "speed") == 0){
            player->speed += buff;
        }
        if (strcmp(tipo, "hp") == 0){
            player->hp += buff;
        }
    
}
  


int main(){

    Stats player = createPlayer();
    Stats enemy;
    int escolha;

    for(;;){
        printf("\n1. Enemy Encounter");
        printf("\n2. Verificar stats de player");
        printf("\n3. Modificar dados de player");
        printf("\n4. Modificar Equipamentos");
        printf("\n5. Sair do jogo\nEscolha: ");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:
            bool Result;

            enemy = FullEnemy(player);
            printf("Um Inimigo se aproxima...\n\n");
            PrintEnemy(&enemy);
            Result = Fight(&player, &enemy);
                if (Result == true){
                    printf("\nParabens");
                    player.hp = FullPlayerHealth;
                } else {
                    printf("\n...");
                    player.hp = FullPlayerHealth;
                }
            break;

            case 2:
            PrintPlayer(&player);
            break;

            case 3:
            PlayerModifier(&player);
            break;

            case 4:
            Equipament(&player);
            break;

            case 5:
            exit(0);
            break;

        }

    }
}