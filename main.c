/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffleitas <ffleitas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:54:37 by ffleitas          #+#    #+#             */
/*   Updated: 2024/07/18 17:50:58 by ffleitas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *routine(void *arg)
{
	long value;
	long *sum;

	value = (long)arg;
	sum = malloc(sizeof(long));
	if (!sum)
		return (NULL);
	*sum = value * 10;
	return ((void *)sum);
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	long	value1;
	long	value2;
	long	*result;

	value1 = 1;
	pthread_create(&thread1, NULL, routine, (void *)value1);
	value2 = 2;
	pthread_create(&thread2, NULL, routine, (void *)value2);
	
	
	pthread_join(thread1, (void **)&result);
	printf("Result thread1: %ld\n", *result);
	free(result);
	pthread_join(thread2, (void **)&result);
	printf("Result thread2: %ld\n", *result);
	free(result);
	return (0);
}
