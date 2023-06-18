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

/*
 * CellQuestions_allOf.h
 *
 * 
 */

#ifndef CellQuestions_allOf_H_
#define CellQuestions_allOf_H_



#include "Question.h"
#include <vector>
#include <memory>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include "helpers.h"

namespace org {
namespace openapitools {
namespace server {
namespace model {

/// <summary>
/// 
/// </summary>
class  CellQuestions_allOf 
{
public:
    CellQuestions_allOf() = default;
    explicit CellQuestions_allOf(boost::property_tree::ptree const& pt);
    virtual ~CellQuestions_allOf() = default;

    CellQuestions_allOf(const CellQuestions_allOf& other) = default; // copy constructor
    CellQuestions_allOf(CellQuestions_allOf&& other) noexcept = default; // move constructor

    CellQuestions_allOf& operator=(const CellQuestions_allOf& other) = default; // copy assignment
    CellQuestions_allOf& operator=(CellQuestions_allOf&& other) noexcept = default; // move assignment

    std::string toJsonString(bool prettyJson = false) const;
    void fromJsonString(std::string const& jsonString);
    boost::property_tree::ptree toPropertyTree() const;
    void fromPropertyTree(boost::property_tree::ptree const& pt);


    /////////////////////////////////////////////
    /// CellQuestions_allOf members

    /// <summary>
    /// 
    /// </summary>
    std::vector<Question> getQuestions() const;
    void setQuestions(std::vector<Question> value);

protected:
    std::vector<Question> m_Questions;
};

std::vector<CellQuestions_allOf> createCellQuestions_allOfVectorFromJsonString(const std::string& json);

template<>
inline boost::property_tree::ptree toPt<CellQuestions_allOf>(const CellQuestions_allOf& val) {
    return val.toPropertyTree();
}

template<>
inline CellQuestions_allOf fromPt<CellQuestions_allOf>(const boost::property_tree::ptree& pt) {
    CellQuestions_allOf ret;
    ret.fromPropertyTree(pt);
    return ret;
}

}
}
}
}

#endif /* CellQuestions_allOf_H_ */