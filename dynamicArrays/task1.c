#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char first_name[50];
    char middle_name[50];
    char last_name[50];
    char email[100];
    char phone_number[20];
} Participant;

typedef struct {
    Participant participant;
    bool will_participate;
} ParticipantResponse;

typedef struct {
    int day;
    int month;
    int year;
    struct {
        int hour;
        int minute;
    } time;
} AnonymousDate;

typedef struct {
    char title[100];
    char description[200];
    AnonymousDate date;
    ParticipantResponse participant_responses[100];
    int num_participants;
} Cause;

int main() {
    Cause causes[2] = {
        {
            .title = "Почистване на парк",
            .description = "Доброволческо почистване на местен парк",
            .date = { .day = 1, .month = 5, .year = 2023, .time = { .hour = 9, .minute = 0 }},
            .participant_responses = {
                { .participant = { "Иван", "Петров", "Георгиев", "ivan@example.com", "+3591234567" }, .will_participate = true },
                { .participant = { "Мария", "Стоянова", "Димитрова", "maria@example.com", "+3592345678" }, .will_participate = false },
            },
            .num_participants = 2
        },
        {
            .title = "Засаждане на дървета",
            .description = "Доброволческа засаждане на дървета в гората",
            .date = { .day = 1, .month = 5, .year = 2023, .time = { .hour = 10, .minute = 30 }},
            .participant_responses = {
                { .participant = { "Nqkoi", "Nqkoi ", "Nqkoi", "neshto@neshto.com", "+3593456789" }, .will_participate = true },
                { .participant = { "Radi", "Radev", "Dimitrov", "neshto@neshto.com1", "+3594567890" }, .will_participate = true },
            },
            .num_participants = 2
        },
    };

    return 0;
}