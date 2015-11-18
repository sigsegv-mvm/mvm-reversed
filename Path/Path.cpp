/* reverse engineering by sigsegv
 * based on TF2 version 20151007a
 * Pathfinding: path
 */


Path::Path()
{
	this->m_iSegCount        = 0;
	this->m_flCursorPosition = 0.0f;
	this->m_bCursorDataDirty = true;
	
	this->m_CursorData.m_pSegment = nullptr;
}

Path::~Path()
{
}


float Path::GetLength() const
{
	if (!this->IsValid()) {
		return 0.0f;
	}
	
	// TODO: name for field_2c
	return this->m_Segments[this->m_iSegCount - 1].m_flStartDist;
}


/* give me the location of the point at distance 'dist' along the path, measured
 * from the start of 'seg' (or the start of the path, if 'seg' is null) */
const Vector& Path::GetPosition(float dist, const Segment *seg) const
{
	if (!this->IsValid()) {
		return vec3_origin;
	}
	
	Vector  pos;
	Vector dpos;
	
	float  s = 0.0f;
	float ds = 0.0f;
	
	if (seg == nullptr) {
		seg = &this->m_Segments[0];
	} else {
		s = seg->m_flStartDist;
	}
	
	if (seg->m_flStartDist > dist) {
		return vec3_origin;
	}
	
	const Segment *seg_this = seg;
	const Segment *seg_next;
	
	while ((seg_next = this->NextSegment(seg_this)) != nullptr) {
		ds = seg_this->m_flLength;
		pos = seg_this->m_vecStart;
		dpos = seg_next->m_vecStart - pos;
		
		if (s + ds >= dist) {
			float fraction = (dist - s) / ds;
			this->m_vecGetPosition = pos + (dpos * fraction);
			return this->m_vecGetPosition;
		}
		
		s += ds;
		seg_this = seg_next;
	}
	
	return seg_this->m_vecStart;
}

/* get the closest point on the path to 'near', starting at segment 'seg' and
 * continuing for distance 'dist' along the path; if 'seg' is null, start at the
 * beginning of the path, and if 'dist' is zero, go all the way to the end of
 * the path */
const Vector& Path::GetClosestPosition(const Vector& near, const Segment *seg, float dist) const
{
	if (seg == nullptr) {
		seg = &this->m_Segments[0];
	}
	
	/* this isn't realistically possible */
	if (seg == nullptr) {
		return near;
	}
	
	this->m_vecGetClosestPosition = near;
	
	float closest_dist_sqr = 1.0e+11f;
	float s = 0.0f;
	
	const Segment *seg_this = seg;
	const Segment *seg_next;
	
	while ((seg_next = this->NextSegment(seg_this)) != nullptr) {
		if (dist != 0.0f && s > dist) {
			break;
		}
		
		Vector point;
		CalcClosestPointOnLineSegment(near,
			seg_this->m_vecStart, seg_next->m_vecStart, point);
		float this_dist_sqr = point.DistToSqr(near);
		
		if (this_dist_sqr < closest_dist_sqr) {
			this->m_vecGetClosestPosition = point;
			closest_dist_sqr = this_dist_sqr;
		}
		
		s += seg_this->m_flLength;
		seg_this = seg_next;
	}
	
	return this->m_vecGetClosestPosition;
}

const Vector& Path::GetStartPosition() const
{
	if (!this->IsValid()) {
		return vec3_origin;
	}
	
	// TODO: name for vector_8
	return this->m_Segments[0].vector_8;
}

const Vector& Path::GetEndPosition() const
{
	if (!this->IsValid()) {
		return vec3_origin;
	}
	
	// TODO: name for vector_8
	return this->m_Segments[this->m_iSegCount - 1].vector_8;
}


CBaseEntity *Path::GetSubject() const
{
	return this->m_hSubject();
}

const Segment *Path::GetCurrentGoal() const
{
	return nullptr;
}

float Path::GetAge() const
{
	return this->m_itAge.GetElapsedTime();
}


/* move the cursor to the closest point on the path to 'near', starting either
 * at the beginning of the path or the current cursor position based on 'stype',
 * and continuing for distance 'dist' along the path */
void Path::MoveCursorToClosestPosition(const Vector& near, SeekType stype, float dist) const
{
	if (!this->IsValid() || stype >= SeekType::MAX) {
		return;
	}
	
	const Segment *seg_this = &this->m_Segments[0];
	const Segment *seg_next;
	
	if (stype == SeekType::FROM_CURSOR) {
		seg = this->m_CursorData.m_pSegment;
		if (seg == nullptr) {
			seg = &this->m_Segments[0];
		}
	}
	
	// TODO: name for field_0
	this->m_CursorData.field_0 = near;
	this->m_CursorData.m_pSegment = seg_this;
	
	float closest_dist_sqr = 1.0e+11f;
	float s = 0.0f;
	
	while ((seg_next = this->NextSegment(seg_this)) != nullptr) {
		if (dist != 0.0f && s > dist) {
			break;
		}
		
		Vector point;
		CalcClosestPointOnLineSegment(near,
			seg_this->m_vecStart, seg_next->m_vecStart, point);
		float this_dist_sqr = point.DistToSqr(near);
		
		if (this_dist_sqr < closest_dist_sqr) {
			// TODO: name for field_0
			this->m_CursorData.field_0 = point;
			this->m_CursorData.m_pSegment = seg_this;
			closest_dist_sqr = this_dist_sqr;
		}
		
		s += seg_this->m_flLength;
		seg_this = seg_next;
	}
	
	const Segment *seg_cur = this->m_CursorData.m_pSegment;
	this->m_flCursorPosition = seg_cur->m_flStartDist +
		seg_cur->m_vecStart.DistTo(this->m_CursorData.field_0);
	// TODO: name for field_0
	this->m_bCursorDataDirty = true;
}

void Path::MoveCursorToStart()
{
	this->m_flCursorPosition = 0.0f;
	this->m_bCursorDataDirty = true;
}

void Path::MoveCursorToEnd()
{
	this->m_flCursorPosition = this->GetLength();
	this->m_bCursorDataDirty = true;
}

void Path::MoveCursor(float dist, MoveCursorType mctype)
{
	if (mctype == MoveCursorType::RELATIVE) {
		dist += this->m_flCursorPosition;
	}
	
	this->m_flCursorPosition = dist;
	
	if (dist < 0.0f) {
		this->m_flCursorPosition = 0.0f;
	} else if (dist > this->GetLength()) {
		this->m_flCursorPosition = this->GetLength();
	}
	
	this->m_bCursorDataDirty = true;
}


float Path::GetCursorPosition() const
{
	return this->m_flCursorPosition;
}

const CursorData *Path::GetCursorData() const
{
	return &this->m_CursorData;
}


bool Path::IsValid() const
{
	return (this->m_iSegCount > 0);
}

void Path::Invalidate()
{
	this->m_iSegCount = 0;
	
	// TODO: names for fields
	this->m_CursorData.field_0  = vec3_origin;
	this->m_CursorData.field_C  = { 1.0f, 0.0f, 0.0f };
	this->m_CursorData.field_18 = 0.0f;
	this->m_CursorData.m_pSegment = nullptr;
	
	this->m_bCursorDataDirty = true;
	this->m_hSubject = nullptr;
}


void Path::Draw(const Segment *seg) const
{
	if (!this->IsValid()) {
		return;
	}
	
	CFmtStrN<256> fmtstr;
	int draw_seg_count = NextBotPathDrawSegmentCount.GetInt();
	
	if (seg == nullptr) {
		seg = this->FirstSegment();
		
		if (seg == nullptr) {
			return;
		}
	}
	
	const Segment *seg_this = seg;
	const Segment *seg_next;
	
	for (int i = 0; i < draw_seg_count; ++i) {
		if ((seg_next = this->NextSegment(seg_this)) == nullptr) {
			return;
		}
		
		int dx = abs((int)(seg_next->m_vecStart.x - seg_this->m_vecStart.x));
		int dy = abs((int)(seg_next->m_vecStart.y - seg_this->m_vecStart.y));
		int dz = abs((int)(seg_next->m_vecStart.z - seg_this->m_vecStart.z));
		
		int dxy = Max(dx, dy);
		
		int r, g, b;
		// TODO: names for Path::SegmentType enum values
		switch (seg_this->m_Type) {
		default: /* orange */
			r = 0xff;
			g = 0x4d;
			b = 0x00;
			break;
		case SegmentType::TYPE1: /* magenta */
			r = 0xff;
			g = 0x00;
			b = 0xff;
			break;
		case SegmentType::TYPE2: /* blue */
			r = 0x00;
			g = 0x00;
			b = 0xff;
			break;
		case SegmentType::TYPE3: /* cyan */
			r = 0x00;
			g = 0xff;
			b = 0xff;
			break;
		case SegmentType::TYPE4: /* green */
			r = 0x00;
			g = 0xff;
			b = 0x00;
			break;
		case SegmentType::TYPE5: /* dark green */
			r = 0x00;
			g = 0x64;
			b = 0x00;
			break;
		}
		
		// TODO: name for field_14
		if (seg_this->field_14 != nullptr) {
			// TODO: name for field14->vector_0
			// TODO: name for field14->vector_c
			NDebugOverlay::VertArrow(seg_this->field_14->vector_c,
				seg_this->field_14->vector_0, 5.0f, r, g, b, 255, true, 0.1f);
		} else {
			NDebugOverlay::Line(seg_this->m_vecStart, seg_next->m_vecStart,
				r, g, b, true, 0.1f);
		}
		
		if (dz_abs > d_xy_abs) {
			// TODO: name for vector_1c
			NDebugOverlay::HorzArrow(seg_this->m_vecStart,
				seg_this->m_vecStart + (25.0f * seg_this->vector_1c),
				5.0f, r, g, b, 255, true, 0.1f);
		} else {
			// TODO: name for vector_1c
			NDebugOverlay::VertArrow(seg_this->m_vecStart,
				seg_this->m_vecStart + (25.0f * seg_this->vector_1c),
				5.0f, r, g, b, 255, true, 0.1f);
		}
		
		NDebugOverlay::Text(seg_this->m_vecStart,
			fmtstr.sprintf("%d", i), true, 0.1f);
		
		seg_this = seg_next;
	}
}

void Path::DrawInterpolated(float from, float to)
{
	if (!this->IsValid()) {
		return;
	}
	
	// TODO: name for field_0
	Vector v_begin = this->GetCursorData()->field_0;
	float dist = from;
	
	do {
		dist += NextBotPathDrawIncrement.GetFloat();
		
		this->MoveCursor(dist, MoveCursorType::ABSOLUTE);
		const CursorData *cur_data = this->GetCursorData();
		
		// TODO: better name for this, plus name for field_18
		float field18_x3 = cur_data->field_18 * 3.0f;
		
		int r = (int)(255.0f * (1.0f - field18_x3));
		int g = (int)(255.0f * (1.0f + field18_x3));
		
		// TODO: name for field_0
		NDebugOverlay::Line(&v_begin, &cur_data->field_0,
			Clamp(r, 0, 255), Clamp(g, 0, 255), 0, true, 0.1f);
		
		// TODO: name for field_0
		v_begin = cur_data->field_0;
	} while (dist < to);
}


const Segment *Path::FirstSegment() const
{
	if (!this->IsValid()) {
		return nullptr;
	}
	
	return &this->m_Segments[0];
}

const Segment *Path::NextSegment(const Segment *seg) const
{
	if (seg == nullptr || !this->IsValid()) {
		return nullptr;
	}
	
	int idx = (seg - this->m_Segments) / sizeof(*seg);
	if (idx >= 0 && idx < (this->m_iSegCount - 1)) {
		return this->m_Segments[idx + 1];
	} else {
		return nullptr;
	}
}

const Segment *Path::PriorSegment(const Segment *seg) const
{
	if (seg == nullptr || !this->IsValid()) {
		return nullptr;
	}
	
	int idx = (seg - this->m_Segments) / sizeof(*seg);
	if (idx > 0 && idx < this->m_iSegCount) {
		return this->m_Segments[idx - 1];
	} else {
		return nullptr;
	}
}

const Segment *Path::LastSegment() const
{
	if (!this->IsValid()) {
		return nullptr;
	}
	
	return &this->m_Segments[this->m_iSegCount - 1];
}


void Path::OnPathChanged(INextBot *nextbot, ResultType rtype)
{
}


void Path::Copy(INextBot *nextbot, const Path& that)
{
	VPROF_BUDGET("Path::Copy", "NextBot");
	
	this->Invalidate();
	
	for (int i = 0; i < that.m_iSegCount; ++i) {
		this->m_Segments[i] = that.m_Segments[i];
	}
	
	this->m_iSegCount = that.m_iSegCount;
	this->OnPathChanged(nextbot, ResultType::ZERO);
}


bool Path::ComputeWithOpenGoal(INextBot *nextbot, const IPathCost& cost, const IPathOpenGoalSelector& sel, float f1)
{
	// TODO
}

void Path::ComputeAreaCrossing(INextBot *nextbot, const CNavArea *area, const Vector& from, const CNavArea *to, NavDirType dir, Vector *out) const
{
	area->ComputeAreaCrossing(to, dir, from, out);
}


void Path::AssemblePrecomputedPath(INextBot *nextbot, const Vector& v1, CNavArea *area)
{
	// TODO
}

bool Path::BuildTrivialPath(INextBot *nextbot, const Vector& v1)
{
	// TODO
}

int Path::FindNextOccludedNode(INextBot *nextbot, int index)
{
	ILocomotion *loco = nextbot->GetLocomotionInterface();
	if (loco == nullptr) {
		return this->m_iSegCount;
	}
	
	Segment *seg = &this->m_Segments[index];
	for (int i = index + 1; i < this->m_iSegCount; ++i) {
		Segment *seg_i = &this->m_Segments[i];
		
		// TODO: enum value
		// TODO: figure out what type is Segment+0x00
		if (seg_i->m_Type != 0 || /* TODO */) {
			return i;
		}
	}
	
	return this->m_iSegCount;
}

void Path::InsertSegment(Segment seg, int index)
{
	if ((this->m_iSegCount + 1) > 255) {
		return;
	}
	
	if (index < this->m_iSegCount) {
		for (int i = this->m_iSegCount; i != index; --i) {
			/* member-by-member copy */
			this->m_Segments[i] = this->m_Segments[i - 1];
		}
	}
	
	/* member-by-member copy */
	this->m_Segments[index] = seg;
	
	++this->m_iSegCount;
}

void Path::Optimize(INextBot *nextbot)
{
}

void Path::PostProcess()
{
	// TODO
}


template<class T> bool Path::Compute(INextBot *nextbot, const Vector& v1, T&, float f1, bool b1)
{
	// TODO
}
