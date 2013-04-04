<?xml version="1.0"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0">
 
    <xsl:output method="html" indent="yes"/>
 
    <xsl:template match="university">
        <transform>
            <xsl:apply-templates/>
        </transform>
    </xsl:template>
 
    <xsl:template match="@name">
        <name>
            <xsl:value-of select="."/>
        </name>
    </xsl:template>
 
    <xsl:template match="name">
        <fullname>
            <xsl:apply-templates/>
            <xsl:apply-templates select="following-sibling::surname" mode="fullname"/>
        </fullname>
    </xsl:template>
 
    <xsl:template match="surname"/>
 
    <xsl:template match="surname" mode="fullname">
        <xsl:text> </xsl:text>
        <xsl:apply-templates/>
    </xsl:template>
 
</xsl:stylesheet>
