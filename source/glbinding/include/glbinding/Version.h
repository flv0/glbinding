#pragma once

#include <string>
#include <set>
#include <utility>

#include <glbinding/glbinding_api.h>


namespace glbinding
{

class GLBINDING_API Version
{
public:
    Version();
    Version(int majorVersion, int minorVersion);

    Version(const Version & version);
    Version(Version && version);

    bool isValid() const;

    const Version & nearest() const;

    using Versions = std::set<Version>;
    static const Versions & versions();
    static const Version & latest();

    operator std::pair<unsigned char,  unsigned char> () const;
    operator std::pair<unsigned short, unsigned short>() const;
    operator std::pair<unsigned int,   unsigned int>  () const;

    std::string toString() const;

    bool isNull() const;

	Version & operator=(const Version & version);
	Version & operator=(Version && version);

	inline bool operator< (const Version & version) const;
	inline bool operator> (const Version & version) const;
	inline bool operator==(const Version & version) const;
	inline bool operator!=(const Version & version) const;
	inline bool operator>=(const Version & version) const;
	inline bool operator<=(const Version & version) const;

public:
    int m_major;
    int m_minor;

protected:
	static const Versions s_validVersions;
    static const Version s_latest;
};

GLBINDING_API std::ostream & operator<<(std::ostream & stream, const Version & version);

} // namespace glbinding
