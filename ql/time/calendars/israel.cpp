/* -*- mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

/*
 Copyright (C) 2015 Paolo Mazzocchi
 Copyright (C) 2015 Riccardo Barone

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it
 under the terms of the QuantLib license.  You should have received a
 copy of the license along with this program; if not, please email
 <quantlib-dev@lists.sf.net>. The license is also available online at
 <http://quantlib.org/license.shtml>.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/

#include <ql/time/calendars/israel.hpp>
#include <ql/errors.hpp>

namespace QuantLib {

    Israel::Israel(Israel::Market market) {
        // all calendar instances share the same implementation instance
        static boost::shared_ptr<Calendar::Impl> SettlementImpl(
                                        new Israel::SettlementImpl);
        static boost::shared_ptr<Calendar::Impl> TelAvivImpl(
                                        new Israel::TelAvivImpl);
        switch (market) {
        case Settlement:
            impl_ = SettlementImpl;
            break;
        case TASE:
            impl_ = TelAvivImpl;
            break;
        default:
            QL_FAIL("unknown market");
        }
    }

    bool Israel::SettlementImpl::isWeekend(Weekday w) const {
        return w == Saturday || w == Sunday;
    }

    bool Israel::SettlementImpl::isBusinessDay(const Date& date) const {
        Weekday w = date.weekday();
        Day d = date.dayOfMonth();
        Month m = date.month();
        Year y = date.year();

        if (isWeekend(w))
            return false;

        return true;
    }

    bool Israel::TelAvivImpl::isWeekend(Weekday w) const {
        return w == Friday || w == Saturday;
    }

    bool Israel::TelAvivImpl::isBusinessDay(const Date& date) const {
        Weekday w = date.weekday();
        Day d = date.dayOfMonth();
        Month m = date.month();
        Year y = date.year();

        if (isWeekend(w)
            //Purim
            || (d == 24 && m == February && y == 2013)
            || (d == 16 && m == March    && y == 2014)
            || (d == 05 && m == March    && y == 2015)
            || (d == 24 && m == March    && y == 2016)
            || (d == 12 && m == March    && y == 2017)
            || (d == 1  && m == March    && y == 2018)
            || (d == 21 && m == March    && y == 2019)
            || (d == 10 && m == March    && y == 2020)
            || (d == 26 && m == February && y == 2021)
            || (d == 17 && m == March    && y == 2022)
            || (d == 7  && m == March    && y == 2023)
            || (d == 24 && m == March    && y == 2024)
            || (d == 14 && m == March    && y == 2025)
            || (d == 3  && m == March    && y == 2026)
            || (d == 23 && m == March    && y == 2027)
            || (d == 12 && m == March    && y == 2028)
            || (d == 1  && m == March    && y == 2029)
            || (d == 19 && m == March    && y == 2030)
            || (d == 9  && m == March    && y == 2031)
            || (d == 26 && m == February && y == 2032)
            || (d == 15 && m == March    && y == 2033)
            || (d == 5  && m == March    && y == 2034)
            || (d == 25 && m == March    && y == 2035)
            || (d == 13 && m == March    && y == 2036)
            || (d == 1  && m == March    && y == 2037)
            || (d == 21 && m == March    && y == 2038)
            || (d == 10 && m == March    && y == 2039)
            || (d == 28 && m == February && y == 2040)
            || (d == 17 && m == March    && y == 2041)
            || (d == 6  && m == March    && y == 2042)
            || (d == 26 && m == March    && y == 2043)
            || (d == 13 && m == March    && y == 2044)
            //Passover I and Passover VII
            || ((((d==25||d==26||d==31)&&m==March)||(d==1&&m==April))&&y==2013)
            || ((d==14||d==15||d==20||d==21) && m == April && y == 2014)
            || ((d==3 ||d==4 ||d==9 ||d==10) && m == April && y == 2015)
            || ((d==22||d==23||d==28||d==29) && m == April && y == 2016)
            || ((d==10||d==11||d==16||d==17) && m == April && y == 2017)
            || (( (d==31&&m==March) ||((d==5||d==6)&&m==April))&&y== 2018)
            || ((d == 20||d == 25 ||d == 26) && m == April && y == 2019)
            || ((d==8 ||d==9 ||d==14||d==15) && m == April && y == 2020)
            || (((d==28&&m==March)||(d==3&&m==April))&&y== 2021)
            || ((d == 16 || d == 22) && m == April && y == 2022)
            || ((d == 6  || d == 12) && m == April && y == 2023)
            || ((d == 23 || d == 29) && m == April && y == 2024)
            || ((d == 13 || d == 19) && m == April && y == 2025)
            || ((d == 2  || d == 8 ) && m == April && y == 2026)
            || ((d == 22 || d == 28) && m == April && y == 2027)
            || ((d == 11 || d == 17) && m == April && y == 2028)
            || (((d==31&&m==March)||(d==6&&m==April))&&y== 2029)
            || ((d == 18 || d == 24) && m == April && y == 2030)
            || ((d == 8  || d == 14) && m == April && y == 2031)
            || (((d==27&&m==March)||(d==2&&m==April))&&y== 2032)
            || ((d == 14 || d == 20) && m == April && y == 2033)
            || ((d == 4  || d == 10) && m == April && y == 2034)
            || ((d == 24 || d == 30) && m == April && y == 2035)
            || ((d == 12 || d == 18) && m == April && y == 2036)
            || (((d==31&&m==March)||(d==6&&m==April))&&y== 2037)
            || ((d == 20 || d == 26) && m == April && y == 2038)
            || ((d == 9  || d == 15) && m == April && y == 2039)
            || (((d==29&&m==March)||(d==4&&m==April))&&y== 2040)
            || ((d == 16 || d == 22) && m == April && y == 2041)
            || ((d == 5  || d == 11) && m == April && y == 2042)
            || (((d==25&&m==April)||(d==1&&m==May))&& y == 2043)
            || ((d == 12 || d == 18) && m == April && y == 2044)
            //Memorial and Indipendence Day
            || ((d == 15 || d == 16) && m == April && y == 2013)
            || ((d == 5  || d == 6 ) && m == May   && y == 2014)
            || ((d == 22 || d == 23) && m == April && y == 2015)
            || ((d == 11 || d == 12) && m == May   && y == 2016)
            || ((d == 1  || d == 2 ) && m == May   && y == 2017)
            || ((d == 18 || d == 19) && m == April && y == 2018)
            || ((d == 8  || d == 9 ) && m == May   && y == 2019)
            || ((d == 28 || d == 29) && m == April && y == 2020)
            || ((d == 14 || d == 15) && m == April && y == 2021)
            || ((d == 4  || d == 5 ) && m == May   && y == 2022)
            || ((d == 25 || d == 26) && m == April && y == 2023)
            || ((d == 13 || d == 14) && m == May   && y == 2024)
            || (((d==30&&m==April)||(d==1&&m==May))&& y == 2025)
            || ((d == 21 || d == 22) && m == April && y == 2026)
            || ((d == 11 || d == 12) && m == May   && y == 2027)
            || ((d == 1  || d == 2 ) && m == May   && y == 2028)
            || ((d == 18 || d == 19) && m == April && y == 2029)
            || ((d == 7  || d == 8 ) && m == May   && y == 2030)
            || ((d == 28 || d == 29) && m == April && y == 2031)
            || ((d == 14 || d == 15) && m == April && y == 2032)
            || ((d == 3  || d == 4 ) && m == May   && y == 2033)
            || ((d == 24 || d == 25) && m == April && y == 2034)
            || ((d == 14 || d == 15) && m == May   && y == 2035)
            || (((d==30&&m==April)||(d==1&&m==May))&& y == 2036)
            || ((d == 20 || d == 21) && m == April && y == 2037)
            || ((d == 9  || d == 10) && m == May   && y == 2038)
            || ((d == 27 || d == 28) && m == April && y == 2039)
            || ((d == 17 || d == 18) && m == April && y == 2040)
            || ((d == 6  || d == 7 ) && m == May   && y == 2041)
            || ((d == 23 || d == 24) && m == April && y == 2042)
            || ((d == 13 || d == 14) && m == May   && y == 2043)
            || ((d == 2  || d == 3 ) && m == May   && y == 2044)
            //Pentecost (Shavuot)
            || ((d == 14 || d == 15) && m == May  && y == 2013)
            || ((d == 3  || d == 4 ) && m == June && y == 2014)
            || ((d == 23 || d == 24) && m == May  && y == 2015)
            || ((d == 11 || d == 12) && m == June && y == 2016)
            || ((d == 30 || d == 31) && m == May  && y == 2017)
            || ((d == 19 || d == 20) && m == May  && y == 2018)
            || ((d == 8  || d == 9 ) && m == June && y == 2019)
            || ((d == 28 || d == 29) && m == May  && y == 2020)
            || (d == 17 && m == May  && y == 2021)
            || (d == 5  && m == June && y == 2022)
            || (d == 26 && m == May  && y == 2023)
            || (d == 12 && m == June && y == 2024)
            || (d == 2  && m == June && y == 2025)
            || (d == 22 && m == May  && y == 2026)
            || (d == 11 && m == June && y == 2027)
            || (d == 31 && m == May  && y == 2028)
            || (d == 20 && m == May  && y == 2029)
            || (d == 7  && m == June && y == 2030)
            || (d == 28 && m == May  && y == 2031)
            || (d == 16 && m == May  && y == 2032)
            || (d == 3  && m == June && y == 2033)
            || (d == 24 && m == May  && y == 2034)
            || (d == 13 && m == June && y == 2035)
            || (d == 1  && m == June && y == 2036)
            || (d == 20 && m == May  && y == 2037)
            || (d == 9  && m == June && y == 2038)
            || (d == 29 && m == May  && y == 2039)
            || (d == 18 && m == May  && y == 2040)
            || (d == 5  && m == June && y == 2041)
            || (d == 25 && m == May  && y == 2042)
            || (d == 14 && m == June && y == 2043)
            || (d == 1  && m == June && y == 2044)
            //Fast Day
            || (d == 16 && m == July   && y == 2013)
            || (d == 5  && m == August && y == 2014)
            || (d == 26 && m == July   && y == 2015)
            || (d == 14 && m == August && y == 2016)
            || (d == 1  && m == August && y == 2017)
            || (d == 22 && m == July   && y == 2018)
            || (d == 11 && m == August && y == 2019)
            || (d == 30 && m == July   && y == 2020)
            || (d == 18 && m == July   && y == 2021)
            || (d == 7  && m == August && y == 2022)
            || (d == 27 && m == July   && y == 2023)
            || (d == 13 && m == August && y == 2024)
            || (d == 3  && m == August && y == 2025)
            || (d == 23 && m == July   && y == 2026)
            || (d == 12 && m == August && y == 2027)
            || (d == 1  && m == August && y == 2028)
            || (d == 22 && m == July   && y == 2029)
            || (d == 8  && m == August && y == 2030)
            || (d == 29 && m == July   && y == 2031)
            || (d == 18 && m == July   && y == 2032)
            || (d == 4  && m == August && y == 2033)
            || (d == 25 && m == July   && y == 2034)
            || (d == 14 && m == August && y == 2035)
            || (d == 3  && m == August && y == 2036)
            || (d == 21 && m == July   && y == 2037)
            || (d == 10 && m == August && y == 2038)
            || (d == 31 && m == July   && y == 2039)
            || (d == 19 && m == July   && y == 2040)
            || (d == 6  && m == August && y == 2041)
            || (d == 27 && m == July   && y == 2042)
            || (d == 16 && m == August && y == 2043)
            || (d == 2  && m == August && y == 2044)
            //Jewish New Year
            || ((d == 4  ||d == 5 || d == 6 ) && m == September && y == 2013)
            || ((d == 24 ||d == 25|| d == 26) && m == September && y == 2014)
            || ((d == 13 ||d == 14|| d == 15) && m == September && y == 2015)
            || ((d == 2  ||d == 3 || d == 4 ) && m == October   && y == 2016)
            || ((d == 20 ||d == 21|| d == 22) && m == September && y == 2017)
            || ((d == 9  ||d == 10|| d == 11) && m == September && y == 2018)
            || ((((d==29||d==30)&&m==September)||(d==1&&m==October))&&y==2019)
            || ((d == 19 || d == 20) && m == September && y == 2020)
            || ((d == 7  || d == 8 ) && m == September && y == 2021)
            || ((d == 26 || d == 27) && m == September && y == 2022)
            || ((d == 16 || d == 17) && m == September && y == 2023)
            || ((d == 3  || d == 4 ) && m == October   && y == 2024)
            || ((d == 23 || d == 24) && m == September && y == 2025)
            || ((d == 12 || d == 13) && m == September && y == 2026)
            || ((d == 2  || d == 3 ) && m == October   && y == 2027)
            || ((d == 21 || d == 22) && m == September && y == 2028)
            || ((d == 10 || d == 11) && m == September && y == 2029)
            || ((d == 28 || d == 29) && m == September && y == 2030)
            || ((d == 18 || d == 19) && m == September && y == 2031)
            || ((d == 6  || d == 7 ) && m == September && y == 2032)
            || ((d == 24 || d == 25) && m == September && y == 2033)
            || ((d == 14 || d == 15) && m == September && y == 2034)
            || ((d == 4  || d == 5 ) && m == October   && y == 2035)
            || ((d == 22 || d == 23) && m == September && y == 2036)
            || ((d == 10 || d == 11) && m == September && y == 2037)
            || (((d==30&&m==September)||(d==01&&m==October))&&y==2038)
            || ((d == 19 || d == 20) && m == September && y == 2039)
            || ((d == 8  || d == 9 ) && m == September && y == 2040)
            || ((d == 26 || d == 27) && m == September && y == 2041)
            || ((d == 15 || d == 16) && m == September && y == 2042)
            || ((d == 5  || d == 6 ) && m == October   && y == 2043)
            || ((d == 22 || d == 23) && m == September && y == 2044)
            //Yom Kippur
            || ((d == 13 || d == 14) && m == September && y == 2013)
            || ((d == 3  || d == 4 ) && m == October   && y == 2014)
            || ((d == 22 || d == 23) && m == September && y == 2015)
            || ((d == 11 || d == 12) && m == October   && y == 2016)
            || ((d == 29 || d == 30) && m == September && y == 2017)
            || ((d == 18 || d == 19) && m == September && y == 2018)
            || ((d == 8  || d == 9 ) && m == October   && y == 2019)
            || ((d == 27 || d == 28) && m == September && y == 2020)
            || ((d == 15 || d == 16) && m == September && y == 2021)
            || ((d == 4  || d == 5 ) && m == October   && y == 2022)
            || ((d == 24 || d == 25) && m == September && y == 2023)
            || ((d == 11 || d == 12) && m == October   && y == 2024)
            || ((d == 1  || d == 2 ) && m == October   && y == 2025)
            || ((d == 20 || d == 21) && m == September && y == 2026)
            || ((d == 10 || d == 11) && m == October   && y == 2027)
            || ((d == 29 || d == 30) && m == September && y == 2028)
            || ((d == 18 || d == 19) && m == September && y == 2029)
            || ((d == 6  || d == 7 ) && m == October   && y == 2030)
            || ((d == 26 || d == 27) && m == September && y == 2031)
            || ((d == 14 || d == 15) && m == September && y == 2032)
            || ((d == 2  || d == 3 ) && m == October   && y == 2033)
            || ((d == 22 || d == 23) && m == September && y == 2034)
            || ((d == 12 || d == 13) && m == October   && y == 2035)
            || (((d==30&&m==September)||(d==01&&m==October))&&y==2036)
            || ((d == 18 || d == 19) && m == September && y == 2037)
            || ((d == 8  || d == 9 ) && m == October   && y == 2038)
            || ((d == 27 || d == 28) && m == September && y == 2039)
            || ((d == 16 || d == 17) && m == September && y == 2040)
            || ((d == 4  || d == 5 ) && m == October   && y == 2041)
            || ((d == 23 || d == 24) && m == September && y == 2042)
            || ((d == 13 || d == 14) && m == October   && y == 2043)
            || (((d==30&&m==September)||(d==01&&m==October))&&y==2044)
            //Sukkoth
            || ((d == 18 || d == 19) && m == September && y == 2013)
            || ((d == 8  || d == 9 ) && m == October   && y == 2014)
            || ((d == 27 || d == 28) && m == September && y == 2015)
            || ((d == 16 || d == 17) && m == October   && y == 2016)
            || ((d == 4  || d == 5 ) && m == October   && y == 2017)
            || ((d == 23 || d == 24) && m == September && y == 2018)
            || ((d == 13 || d == 14) && m == October   && y == 2019)
            || ((d == 2  || d == 3 ) && m == October   && y == 2020)
            || ((d == 20 || d == 21) && m == September && y == 2021)
            || ((d == 9  || d == 10) && m == October   && y == 2022)
            || ((d == 29 || d == 30) && m == September && y == 2023)
            || ((d == 16 || d == 17) && m == October   && y == 2024)
            || ((d == 6  || d == 7 ) && m == October   && y == 2025)
            || ((d == 25 || d == 26) && m == September && y == 2026)
            || ((d == 15 || d == 16) && m == October   && y == 2027)
            || ((d == 4  || d == 5 ) && m == October   && y == 2028)
            || ((d == 23 || d == 24) && m == September && y == 2029)
            || ((d == 11 || d == 12) && m == October   && y == 2030)
            || ((d == 1  || d == 2 ) && m == October   && y == 2031)
            || ((d == 19 || d == 20) && m == September && y == 2032)
            || ((d == 7  || d == 8 ) && m == October   && y == 2033)
            || ((d == 27 || d == 28) && m == September && y == 2034)
            || ((d == 17 || d == 18) && m == October   && y == 2035)
            || ((d == 5  || d == 6 ) && m == October   && y == 2036)
            || ((d == 23 || d == 24) && m == September && y == 2037)
            || ((d == 13 || d == 14) && m == October   && y == 2038)
            || ((d == 2  || d == 3 ) && m == October   && y == 2039)
            || ((d == 21 || d == 22) && m == September && y == 2040)
            || ((d == 9  || d == 10) && m == October   && y == 2041)
            || ((d == 28 || d == 29) && m == September && y == 2042)
            || ((d == 18 || d == 19) && m == October   && y == 2043)
            || ((d == 5  || d == 6 ) && m == October   && y == 2044)
            //Simchat Tora
            || ((d == 25 || d == 26) && m == September && y == 2013)
            || ((d == 15 || d == 16) && m == October   && y == 2014)
            || ((d == 4  || d == 5 ) && m == October   && y == 2015)
            || ((d == 23 || d == 24) && m == October   && y == 2016)
            || ((d == 11 || d == 12) && m == October   && y == 2017)
            || ((d==30&&m==September)||(d==1&&m==October)&&y== 2018)
            || ((d == 20 || d == 21) && m == October   && y == 2019)
            || ((d == 9  || d == 10) && m == October   && y == 2020)
            || ((d == 27 || d == 28) && m == September && y == 2021)
            || ((d == 16 || d == 17) && m == October   && y == 2022)
            || ((d == 6  || d == 7 ) && m == October   && y == 2023)
            || ((d == 23 || d == 24) && m == October   && y == 2024)
            || ((d == 13 || d == 14) && m == October   && y == 2025)
            || ((d == 2  || d == 3 ) && m == October   && y == 2026)
            || ((d == 22 || d == 23) && m == October   && y == 2027)
            || ((d == 11 || d == 12) && m == October   && y == 2028)
            || ((d==30&&m==September)||(d==1&&m==October)&&y== 2029)
            || ((d == 18 || d == 19) && m == October   && y == 2030)
            || ((d == 8  || d == 9 ) && m == October   && y == 2031)
            || ((d == 26 || d == 27) && m == September && y == 2032)
            || ((d == 14 || d == 15) && m == October   && y == 2033)
            || ((d == 4  || d == 5 ) && m == October   && y == 2034)
            || ((d == 24 || d == 25) && m == October   && y == 2035)
            || ((d == 12 || d == 13) && m == October   && y == 2036)
            || ((d==30&&m==September)||(d==1&&m==October)&&y== 2037)
            || ((d == 20 || d == 21) && m == October   && y == 2038)
            || ((d == 9  || d == 10) && m == October   && y == 2039)
            || ((d == 28 || d == 29) && m == September && y == 2040)
            || ((d == 16 || d == 17) && m == October   && y == 2041)
            || ((d == 5  || d == 6 ) && m == October   && y == 2042)
            || ((d == 25 || d == 26) && m == October   && y == 2043)
            || ((d == 12 || d == 13) && m == October   && y == 2044))
            return false;

        return true;
    }

}
