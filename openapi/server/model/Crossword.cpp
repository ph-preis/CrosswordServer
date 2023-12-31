/**
 * Crossword provider
 * Access to crosswords puzzle generator
 *
 * The version of the OpenAPI document: 1.0.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI-Generator 6.6.0.
 * https://openapi-generator.tech
 * Do not edit the class manually.
 */



#include "Crossword.h"

#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stdexcept>
#include <regex>
#include <boost/lexical_cast.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "helpers.h"

using boost::property_tree::ptree;
using boost::property_tree::read_json;
using boost::property_tree::write_json;

namespace org {
namespace openapitools {
namespace server {
namespace model {

Crossword::Crossword(boost::property_tree::ptree const& pt)
{
        fromPropertyTree(pt);
}


std::string Crossword::toJsonString(bool prettyJson /* = false */) const
{
	std::stringstream ss;
	write_json(ss, this->toPropertyTree(), prettyJson);
    // workaround inspired by: https://stackoverflow.com/a/56395440
    std::regex reg("\\\"([0-9]+\\.{0,1}[0-9]*)\\\"");
    std::string result = std::regex_replace(ss.str(), reg, "$1");
    return result;
}

void Crossword::fromJsonString(std::string const& jsonString)
{
	std::stringstream ss(jsonString);
	ptree pt;
	read_json(ss,pt);
	this->fromPropertyTree(pt);
}

ptree Crossword::toPropertyTree() const
{
	ptree pt;
	ptree tmp_node;
	pt.put("id", m_Id);
	pt.put("name", m_Name);
	pt.put("width", m_Width);
	pt.put("height", m_Height);
	pt.put("solutionWord", m_SolutionWord);
	// generate tree for Content
    tmp_node.clear();
	if (!m_Content.empty()) {
        tmp_node = toPt(m_Content);
		pt.add_child("content", tmp_node);
		tmp_node.clear();
	}
	return pt;
}

void Crossword::fromPropertyTree(ptree const &pt)
{
	ptree tmp_node;
	m_Id = pt.get("id", 0L);
	m_Name = pt.get("name", "");
	m_Width = pt.get("width", 0);
	m_Height = pt.get("height", 0);
	m_SolutionWord = pt.get("solutionWord", "");
	// push all items of Content into member
	if (pt.get_child_optional("content")) {
        m_Content = fromPt<std::vector<std::vector<Crossword_content_inner_inner>>>(pt.get_child("content"));
	}
}

int64_t Crossword::getId() const
{
    return m_Id;
}

void Crossword::setId(int64_t value)
{
    m_Id = value;
}


std::string Crossword::getName() const
{
    return m_Name;
}

void Crossword::setName(std::string value)
{
    m_Name = value;
}


int32_t Crossword::getWidth() const
{
    return m_Width;
}

void Crossword::setWidth(int32_t value)
{
    m_Width = value;
}


int32_t Crossword::getHeight() const
{
    return m_Height;
}

void Crossword::setHeight(int32_t value)
{
    m_Height = value;
}


std::string Crossword::getSolutionWord() const
{
    return m_SolutionWord;
}

void Crossword::setSolutionWord(std::string value)
{
    m_SolutionWord = value;
}


std::vector<std::vector<Crossword_content_inner_inner>> Crossword::getContent() const
{
    return m_Content;
}

void Crossword::setContent(std::vector<std::vector<Crossword_content_inner_inner>> value)
{
    m_Content = value;
}



std::vector<Crossword> createCrosswordVectorFromJsonString(const std::string& json)
{
    std::stringstream sstream(json);
    boost::property_tree::ptree pt;
    boost::property_tree::json_parser::read_json(sstream,pt);

    auto vec = std::vector<Crossword>();
    for (const auto& child: pt) {
        vec.emplace_back(Crossword(child.second));
    }

    return vec;
}

}
}
}
}

