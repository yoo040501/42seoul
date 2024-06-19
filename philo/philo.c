/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongeunk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:30:17 by dongeunk          #+#    #+#             */
/*   Updated: 2024/06/08 14:25:06 by dongeunk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_INCREMENTS 1000000

int sharedData = 0;
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *incrementCounter(void *mutex) {
    for (int i = 0; i < NUM_INCREMENTS; ++i) {
        // 뮤텍스 락
        pthread_mutex_lock(mutex);

        sharedData++; // 공유된 변수 증가 연산

        // 뮤텍스 언락
        pthread_mutex_unlock(mutex);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    pthread_mutex_t mutex;

    pthread_mutex_init(&mutex, NULL);
    // 두 개의 스레드 생성
    for (long t = 0; t < 2; ++t) {
        int result = pthread_create(&threads[t], NULL, incrementCounter, (void *)&mutex);
    }

    // 모든 스레드의 실행이 종료될 때까지 대기
    for (long t = 0; t < 2; ++t) {
        int result = pthread_join(threads[t], NULL);
    }

    // 최종 결과 출력
    printf("Final value of sharedData: %d\n", sharedData);

    // 뮤텍스 소멸
    pthread_mutex_destroy(&mutex);

    return 0;
}
