//
// Created by user on 6/18/23.
//

#ifndef BUILDDIR_CROSSWORDEXAMPLE_H
#define BUILDDIR_CROSSWORDEXAMPLE_H


#include "openapi/server/api/DefaultApi.h"

using namespace org;
using namespace openapitools;
using namespace server;
using namespace api;
using namespace DefaultApiResources;

// convert CellLetter to Crossword_content_inner_inner
// This is necessary because the generated openAPI cannot handle arrays with heterogeneous data types
Crossword_content_inner_inner toContent(const CellLetter& cellLetter)
{
    Crossword_content_inner_inner result;
    result.setColor(cellLetter.getColor());
    result.setLetter(cellLetter.getLetter());
    result.setSolutionWordIndex(cellLetter.getSolutionWordIndex());
    return result;
}

// convert CellQuestions to Crossword_content_inner_inner
// This is necessary because the generated openAPI cannot handle arrays with heterogeneous data types
Crossword_content_inner_inner toContent(const CellQuestions& cellQuestions)
{
    Crossword_content_inner_inner result;
    result.setColor(cellQuestions.getColor());
    result.setQuestions(cellQuestions.getQuestions());
    return result;
}

// get a simple example of a crossword puzzle
Crossword getCrosswordExample()
{

    Crossword crosswordExample;
    crosswordExample.setName("Sample");
    crosswordExample.setId(1);
    crosswordExample.setWidth(5);
    crosswordExample.setHeight(5);


    std::vector<Crossword_content_inner_inner> row1 = {
            []{
                CellQuestions cell;
                cell.setQuestions(std::vector<Question>{
                        []{Question q;
                            q.setQuestion("Königliche Kopfbedeckung");
                            q.setAnswer("krone");
                            q.setAnswerStartCell("bottom");
                            q.setAnswerDirection("right");
                            return q;}(),
                        []{Question q;
                            q.setQuestion("Alter Mann");
                            q.setAnswer("greis");
                            q.setAnswerStartCell("right");
                            q.setAnswerDirection("down");
                            return q;}(),
                });
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("g");
                return toContent(cell);}(),
            []{
                CellQuestions cell;
                cell.setQuestions(std::vector<Question>{
                        []{Question q;
                            q.setQuestion("Stadt und Landkreis in Nordrhein-Westfalen");
                            q.setAnswer("olpe");
                            q.setAnswerStartCell("bottom");
                            q.setAnswerDirection("down");
                            return q;}(),
                });
                return toContent(cell);}(),
            []{
                CellQuestions cell;
                cell.setQuestions(std::vector<Question>{
                        []{Question q;
                            q.setQuestion("Hundename");
                            q.setAnswer("bello");
                            q.setAnswerStartCell("right");
                            q.setAnswerDirection("down");
                            return q;}(),
                });
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("b");
                return toContent(cell);}(),
    };

    std::vector<Crossword_content_inner_inner> row2 = {
            []{
                CellLetter cell;
                cell.setLetter("k");
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("r");
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("o");
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("n");
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("e");
                return toContent(cell);}(),
    };

    std::vector<Crossword_content_inner_inner> row3 = {
            []{
                CellQuestions cell;
                cell.setQuestions(std::vector<Question>{
                        []{Question q;
                            q.setQuestion("Spanischer Artikel (m)");
                            q.setAnswer("el");
                            q.setAnswerStartCell("right");
                            q.setAnswerDirection("right");
                            return q;}(),
                });
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("e");
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("l");
                return toContent(cell);}(),
            []{
                CellQuestions cell;
                cell.setQuestions(std::vector<Question>{
                        []{Question q;
                            q.setQuestion("engl. oder");
                            q.setAnswer("or");
                            q.setAnswerStartCell("bottom");
                            q.setAnswerDirection("down");
                            return q;}(),
                });
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("l");
                return toContent(cell);}(),
    };

    std::vector<Crossword_content_inner_inner> row4 = {
            []{
                CellLetter cell;
                cell.setLetter("d");
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("i");
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("p");
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("o");
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("l");
                return toContent(cell);}(),
    };

    std::vector<Crossword_content_inner_inner> row5 = {
            []{
                CellQuestions cell;
                cell.setQuestions(std::vector<Question>{
                        []{Question q;
                            q.setQuestion("Altrohstoffkombinat der DDR");
                            q.setAnswer("sero");
                            q.setAnswerStartCell("right");
                            q.setAnswerDirection("right");
                            return q;}(),
                });
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("s");
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("e");
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("r");
                return toContent(cell);}(),
            []{
                CellLetter cell;
                cell.setLetter("o");
                return toContent(cell);}(),
    };

    crosswordExample.setContent( {row1, row2, row3, row4, row5});

}

#endif //BUILDDIR_CROSSWORDEXAMPLE_H
