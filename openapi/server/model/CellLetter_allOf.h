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
 * CellLetter_allOf.h
 *
 * 
 */

#ifndef CellLetter_allOf_H_
#define CellLetter_allOf_H_



#include <string>
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
class  CellLetter_allOf 
{
public:
    CellLetter_allOf() = default;
    explicit CellLetter_allOf(boost::property_tree::ptree const& pt);
    virtual ~CellLetter_allOf() = default;

    CellLetter_allOf(const CellLetter_allOf& other) = default; // copy constructor
    CellLetter_allOf(CellLetter_allOf&& other) noexcept = default; // move constructor

    CellLetter_allOf& operator=(const CellLetter_allOf& other) = default; // copy assignment
    CellLetter_allOf& operator=(CellLetter_allOf&& other) noexcept = default; // move assignment

    std::string toJsonString(bool prettyJson = false) const;
    void fromJsonString(std::string const& jsonString);
    boost::property_tree::ptree toPropertyTree() const;
    void fromPropertyTree(boost::property_tree::ptree const& pt);


    /////////////////////////////////////////////
    /// CellLetter_allOf members

    /// <summary>
    /// 
    /// </summary>
    std::string getLetter() const;
    void setLetter(std::string value);

    /// <summary>
    /// 
    /// </summary>
    int32_t getSolutionWordIndex() const;
    void setSolutionWordIndex(int32_t value);

protected:
    std::string m_Letter = "";
    int32_t m_SolutionWordIndex = 0;
};

std::vector<CellLetter_allOf> createCellLetter_allOfVectorFromJsonString(const std::string& json);

template<>
inline boost::property_tree::ptree toPt<CellLetter_allOf>(const CellLetter_allOf& val) {
    return val.toPropertyTree();
}

template<>
inline CellLetter_allOf fromPt<CellLetter_allOf>(const boost::property_tree::ptree& pt) {
    CellLetter_allOf ret;
    ret.fromPropertyTree(pt);
    return ret;
}

}
}
}
}

#endif /* CellLetter_allOf_H_ */
