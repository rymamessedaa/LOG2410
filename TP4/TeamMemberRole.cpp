#include "TeamMemberRole.h"
#include <QPainter>
#include <QFont>

TeamMemberRole::TeamMemberRole(std::string name, const class QImage& photo, std::string role)
	: m_member(new TeamMember(name, photo)), m_role(role), m_image(m_member->getImage())
{
	QPainter painter(&m_image);
	QFont font = painter.font();
	font.setPixelSize(24);
	painter.setFont(font);

	const QRect rectangle = QRect(0, 0, 500, 50);
	QRect boundingRect;
	painter.drawText(rectangle, 0, m_role.c_str(), &boundingRect);
}

TeamMemberRole::TeamMemberRole(const TeamMemberRole & mdd)
	: m_member(mdd.m_member->clone()), m_role(mdd.m_role), m_image(mdd.m_image)
{
}

TeamMemberRole * TeamMemberRole::clone(void) const
{
	// renvoi d'une nouvelle instance construite par copie avec l'objet actuelle
	return new TeamMemberRole(*this);
}

const QImage & TeamMemberRole::getImage(void) const
{
	// Renvoi de l'attribut m_image
	return m_image;
}

QImage & TeamMemberRole::getImage(void)
{
	// Renvoi de l'attribut m_image
	return m_image;
}

std::string TeamMemberRole::getName(void) const
{
	// Renvoi de l'attribut m_name de *m_member
	return m_member->getName();
}

void TeamMemberRole::setName(std::string name)
{
	// modification de l'attribut m_name de *m_member
	m_member->setName(name);
}

std::string TeamMemberRole::getRole(void) const
{
	// Renvoi de l'attribut m_role
	return m_role;
}

void TeamMemberRole::setRole(std::string role)
{
	// modification de l'attribut m_role
	m_role = role;
}

AbsTeamComponent& TeamMemberRole::addTeamComponent(const AbsTeamComponent& child)
{
	//deleguer a l'objet membre
	return m_member->addTeamComponent(child);
}

TeamComponentIterator TeamMemberRole::begin()
{
	// deleguer a l'objet membre
	return m_member->begin();
}

TeamComponentIterator_const TeamMemberRole::cbegin() const
{
	//  deleguer a l'objet membre
	return m_member->cbegin();
}

TeamComponentIterator_const TeamMemberRole::cend() const
{
	// deleguer a l'objet membre
	return m_member->cend();
}

TeamComponentIterator TeamMemberRole::end()
{
	// deleguer a l'objet membre
	return m_member->end();
}

void TeamMemberRole::deleteTeamComponent(TeamComponentIterator_const child)
{
	//deleguer a l'objet membre
	return m_member->deleteTeamComponent(child);
}

