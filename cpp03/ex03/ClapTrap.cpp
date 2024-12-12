/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hipham <hipham@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:55:11 by hipham            #+#    #+#             */
/*   Updated: 2024/12/10 14:17:46 by hipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap(): _Name("Default"), _HitPoints(100), _EnergyPoints(100), _AttackDamage(40){
	std::cout << "ClapTrap constructor called" << std::endl;
}
// Parameterized Constructor
ClapTrap::ClapTrap(std::string name): _Name(name), _HitPoints(100), _EnergyPoints(100), _AttackDamage(40){
	std::cout << "ClapTrap constructor called" << std::endl;
}
// Copy constructor
ClapTrap::ClapTrap(const ClapTrap &other) :
	_Name(other._Name),
	_HitPoints(other._HitPoints),
	_EnergyPoints(other._EnergyPoints),
	_AttackDamage(other._AttackDamage) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
}
// Copy assignment operator
ClapTrap &ClapTrap::operator=(ClapTrap &other) {
	std::cout << "ClapTrap copy assigment called" << std::endl;
	if (this != &other) {
		_Name = other._Name;
		_HitPoints = other._HitPoints;
		_EnergyPoints = other._EnergyPoints;
		_AttackDamage = other._AttackDamage;
	}
	return (*this);
}
// Destructor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap copy destructor called" << std::endl;
}

// Setter
void ClapTrap::setName(const std::string name) {
	_Name = name;
}

// Getter 
std::string ClapTrap::getName() {
	return (_Name);
}
unsigned int ClapTrap::getAttackDamage() {
	return (_AttackDamage);
}
unsigned int ClapTrap::getHitPoints() {
	return (_HitPoints);
}
unsigned int ClapTrap::getEnergyPoints() {
	return (_EnergyPoints);
}

// When ClapTrap attacks, it causes its target to lose <attack damage> hit points.
// Attacking and repairing cost 1 energy point each. 
void ClapTrap::attack(const std::string& target) {
	if (_HitPoints > 0 && _EnergyPoints > 0) {
		std::cout << _Name << " attacks " << target;
		std::cout << " caused " << _AttackDamage << " damage" << std::endl;
		_EnergyPoints--;
	}
	else if (_HitPoints <= 0) 
		std::cout << _Name << " does not have HitPoints to attack " << target << std::endl;
	else if (_EnergyPoints <= 0)
		std::cout << _Name << " does not have EnergyPoints to attack " << target << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_HitPoints < amount) {
		std::cout << std::endl;
		std::cout << _Name << " cannot take more Damage" << std::endl;
	}
	else {
		_HitPoints = _HitPoints - amount;
	}
}

// When ClapTrap repairs itself, it gets <amount> hit points back
void ClapTrap::beRepaired(unsigned int amount) {
	if (_EnergyPoints <= 0)
		std::cout << _Name << " does not have enough EnergyPoints to HEAL" << std::endl;
	else {
		std::cout << _Name << " is healing" << std::endl;
		std::cout << _Name << " get " << amount << " Hitpoints back" << std::endl;
		_EnergyPoints--;
		_HitPoints = _HitPoints + amount;
	}
}