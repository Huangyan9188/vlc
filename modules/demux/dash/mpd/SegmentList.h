/*
 * SegmentList.h
 *****************************************************************************
 * Copyright (C) 2010 - 2012 Klagenfurt University
 *
 * Created on: Jan 27, 2012
 * Authors: Christopher Mueller <christopher.mueller@itec.uni-klu.ac.at>
 *          Christian Timmerer  <christian.timmerer@itec.uni-klu.ac.at>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef SEGMENTLIST_H_
#define SEGMENTLIST_H_

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "mpd/SegmentInfoCommon.h"
#include "mpd/ICanonicalUrl.hpp"
#include "Properties.hpp"

#include <vlc_common.h>

namespace dash
{
    namespace mpd
    {
        class SegmentList : public SegmentInfoCommon
        {
            public:
                SegmentList             ( ICanonicalUrl * = NULL );
                virtual ~SegmentList    ();

                const std::vector<Segment *>&   getSegments() const;
                void                    addSegment(Segment *seg);

                Property<uint64_t> timescale;

            private:
                std::vector<Segment *>  segments;
        };
    }
}

#endif /* SEGMENTLIST_H_ */
