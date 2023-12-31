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



#include "CellQuestions.h"

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

CellQuestions::CellQuestions(boost::property_tree::ptree const& pt)
{
        fromPropertyTree(pt);
}


std::string CellQuestions::toJsonString(bool prettyJson /* = false */) const
{
	std::stringstream ss;
	write_json(ss, this->toPropertyTree(), prettyJson);
    // workaround inspired by: https://stackoverflow.com/a/56395440
    std::regex reg("\\\"([0-9]+\\.{0,1}[0-9]*)\\\"");
    std::string result = std::regex_replace(ss.str(), reg, "$1");
    return result;
}

void CellQuestions::fromJsonString(std::string const& jsonString)
{
	std::stringstream ss(jsonString);
	ptree pt;
	read_json(ss,pt);
	this->fromPropertyTree(pt);
}

ptree CellQuestions::toPropertyTree() const
{
	ptree pt;
	ptree tmp_node;
	pt.put("color", m_Color);
	// generate tree for Questions
    tmp_node.clear();
	if (!m_Questions.empty()) {
        tmp_node = toPt(m_Questions);
		pt.add_child("questions", tmp_node);
		tmp_node.clear();
	}
	return pt;
}

void CellQuestions::fromPropertyTree(ptree const &pt)
{
	ptree tmp_node;
	m_Color = pt.get("color", "");
	// push all items of Questions into member
	if (pt.get_child_optional("questions")) {
        m_Questions = fromPt<std::vector<Question>>(pt.get_child("questions"));
	}
}

std::string CellQuestions::getColor() const
{
    return m_Color;
}

void CellQuestions::setColor(std::string value)
{
    m_Color = value;
}


std::vector<Question> CellQuestions::getQuestions() const
{
    return m_Questions;
}

void CellQuestions::setQuestions(std::vector<Question> value)
{
    m_Questions = value;
}



std::vector<CellQuestions> createCellQuestionsVectorFromJsonString(const std::string& json)
{
    std::stringstream sstream(json);
    boost::property_tree::ptree pt;
    boost::property_tree::json_parser::read_json(sstream,pt);

    auto vec = std::vector<CellQuestions>();
    for (const auto& child: pt) {
        vec.emplace_back(CellQuestions(child.second));
    }

    return vec;
}

}
}
}
}

