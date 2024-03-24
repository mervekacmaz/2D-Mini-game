/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eisikogl <eisikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 04:00:18 by eisikogl          #+#    #+#             */
/*   Updated: 2022/08/19 04:18:25 by eisikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

/*
*   Allocates (with malloc(3)) and returns a new node.
*   The member variable ’content’ is initialized with
*   the value of the parameter ’content’. The variable
*   ’next’ is initialized to NULL.
*/

t_list  *ft_lstnew(void *content)
{
    t_list *new;

    new = (t_list *)malloc(sizeof(t_list));
    if(!new)
        return (0);
    new->next = 0;
    new->content = content;
    return (new);
}