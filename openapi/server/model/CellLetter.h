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
 * CellLetter.h
 *
 * 
 */

#ifndef CellLetter_H_
#define CellLetter_H_



#include <string>
#include <memory>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include "Cell.h"
#include "CellLetter_allOf.h"
#include "helpers.h"

namespace org {
namespace openapitools {
namespace server {
namespace model {

/// <summary>
/// 
/// </summary>
class  CellLetter : public Cell, public CellLetter_allOf
{
public:
    CellLetter() = default;
    explicit CellLetter(boost::property_tree::ptree const& pt);
    virtual ~CellLetter() = default;

    CellLetter(const CellLetter& other) = default; // copy constructor
    CellLetter(CellLetter&& other) noexcept = default; // move constructor

    CellLetter& operator=(const CellLetter& other) = default; // copy assignment
    CellLetter& operator=(CellLetter&& other) noexcept = default; // move assignment

    std::string toJsonString(bool prettyJson = false) const;
    void fromJsonString(std::string const& jsonString);
    boost::property_tree::ptree toPropertyTree() const;
    void fromPropertyTree(boost::property_tree::ptree const& pt);


    /////////////////////////////////////////////
    /// CellLetter members

    /// <summary>
    /// 
    /// </summary>
    std::string getColor() const;
    void setColor(std::string value);

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
    std::string m_Color = "";
    std::string m_Letter = "";
    int32_t m_SolutionWordIndex = 0;
};

std::vector<CellLetter> createCellLetterVectorFromJsonString(const std::string& json);

template<>
inline boost::property_tree::ptree toPt<CellLetter>(const CellLetter& val) {
    return val.toPropertyTree();
}

template<>
inline CellLetter fromPt<CellLetter>(const boost::property_tree::ptree& pt) {
    CellLetter ret;
    ret.fromPropertyTree(pt);
    return ret;
}

}
}
}
}

#endif /* CellLetter_H_ */