/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:55:14 by hipham            #+#    #+#             */
/*   Updated: 2024/12/09 15:22:02 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <string>

class ClapTrap {
	private:
		std::string _Name;
		unsigned int _HitPoints = 10;
		unsigned int _EnergyPoints = 10;
		unsigned int _AttackDamage = 0;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(ClapTrap &other);
		~ClapTrap();

		// Setter
		void setName(const std::string name);
		
		// // Getter
		std::string getName();
		unsigned int getAttackDamage();
		unsigned int getHitPoints();
		unsigned int getEnergyPoints();

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif