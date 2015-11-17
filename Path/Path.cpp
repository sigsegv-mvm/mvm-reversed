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

const Vector& Path::GetClosestPosition(const Vector& v1, const Segment *seg, float f1) const
{
	// TODO
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
	// TODO
}

float Path::GetAge() const
{
	return this->m_itAge.GetElapsedTime();
}


void Path::MoveCursorToClosestPosition(const Vector&, SeekType stype, float f1) const
{
	// TODO
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

CursorData *Path::GetCursorData() const
{
	// TODO
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
	// TODO
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
	// TODO
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
