/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:44:03 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/27 11:16:13 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_node);

void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (new_node)
		return ;
	new_node->next = *lst;
	*lst = new_node;
}
