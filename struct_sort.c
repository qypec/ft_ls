/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wconnell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:20:11 by wconnell          #+#    #+#             */
/*   Updated: 2019/04/12 17:20:15 by wconnell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/* Useful stuff */

void	content_cpy(t_file *src, t_file *tmp)
{
	tmp->name = src->name;
	tmp->path = src->path;
	tmp->type = src->type;
	tmp->modif = src->modif;
	tmp->date = src->date;
	tmp->username = src->username;
	tmp->size = src->size;
	tmp->year = src->year;
	tmp->numlink = src->numlink;
	tmp->chmod = src->chmod;
}

void	ft_lstswap(t_file *p1, t_file *p2)
{
	t_file	*tmp;

	tmp = p1;
	content_cpy(p2, p1);
	content_cpy(tmp, p2);
}
int 	ft_lstlength(t_file **head)
{
	t_file	*tmp;
	int		l;

	l = 0;
	tmp = *head;
	while (tmp != NULL)
	{
		l++;
		tmp = tmp->next;
	}
	return (l);
}
void	asciiBubble(t_file **head, int count)
{
	t_file		*h;
	t_file		*p1;
	t_file		*p2;
	int 		i;
	int 		j;
	int 		f;

	f = 0;
	i = 0;
	while (i <= count)
	{
		h = *head;
		f = 0;
		j = 0;
		while (j < count - i - 1)
		{
			p1 = h;
			p2 = h->next;
			if (ft_strcmp(p1->name, p2->name) > 0)
			{
				h = ft_lstswap(p1, p2);
				f++;
			}
			j++;
			h = h->next;
		}
		if (f == 0)
			break;
		i++;
	}
}
void	sort_list(t_file **head, t_flags *flags)
{
	asciiBubble(head, ft_lstlength(head));
//	if (flags->t == 1)
//		sort_by_time(head);
//	if (flags->r == 1)
//		sort_by_reverse(head);
}
//nextint bubbleSort(struct Node** head, int count)
//{
//	struct Node** h;
//	int i, j, swapped;ft_strcmp
//
//	for (i = 0; i <= count; i++) {i
//
//		h = head;
//		swapped = 0;
//
//		for (j = 0; j < count - i - 1; j++) {
//
//			struct Node* p1 = *h;
//			struct Node* p2 = p1->next;
//
//			if (p1->data > p2->data) {
//
//				/* update the link after swapping */
//				*h = swap(p1, p2);
//				swapped = 1;
//			}
//
//			h = &(*h)->next;
//		}
//
//		/* break if the loop ended without any swap */
//		if (swapped == 0)
//			break;
//	}
//}
//
///* Function to print the list */
//void printList(struct Node* n)
//{
//	while (n != NULL) {
//		printf("%d -> ", n->data);
//		n = n->next;
//	}
//	printf("\n");
//}
///* structure for a node */
//struct Node {
//	int data;
//	struct Node* next;
//} Node;
//
///*Function to swap the nodes */
//struct Node* swap(struct Node* ptr1, struct Node* ptr2)
//{
//	struct Node* tmp;
//	tmp = ptr2->next;
//	ptr2->next = ptr1;
//	ptr1->next = tmp;
//	return ptr2;
//}
//
///* Function to sort the list */
///* Function to insert a struct Node
//   at the beginning of a linked list */
//void insertAtTheBegin(struct Node** start_ref, int data)
//{
//	struct Node* ptr1
//			= (struct Node*)malloc(sizeof(struct Node));
//
//	ptr1->data = data;
//	ptr1->next = *start_ref;
//	*start_ref = ptr1;
//}
//
//// Driver Code
//int main()
//{
//	int arr[] = { 78, 20, 10, 32, 1, 5 };
//	int list_size, i;
//
//	/* start with empty linked list */
//	struct Node* start = NULL;
//	list_size = sizeof(arr) / sizeof(arr[0]);
//
//	/* Create linked list from the array arr[] */
//	for (i = 0; i < list_size; i++)
//		insertAtTheBegin(&start, arr[i]);
//
//	/* print list before sorting */
//	printf("Linked list before sorting\n");
//	printList(start);
//
//	/* sort the linked list */
//	bubbleSort(&start, list_size);
//
//	/* print list after sorting */
//	printf("Linked list after sorting\n");
//	printList(start);
//
//	return 0;
//}


//void		lsort_ascii(t_file **head)
//{
//	t_file	*tmp;
//	t_file	*curr;
//	t_file	*next;
//	t_file	*prev;
//	int 	f;
//	f = 1;
//	while(f--)
//	{
//		prev = *head;
//		curr = prev->next;
//		f = 0;
//		while ((curr != NULL)
//		{
//			next = curr->next;
//			if()
//			curr = curr->next;
//		}
//	}
//}curr

