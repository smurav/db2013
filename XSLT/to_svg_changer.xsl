<?xml version="1.0" encoding="UTF-8"?>

<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

<xsl:output method="xml" indent="yes" />
<xsl:variable name="globminlon" select="/osm/bounds/@minlon" />
<xsl:variable name="globmaxlon" select="/osm/bounds/@maxlon" />
<xsl:variable name="globminlat" select="/osm/bounds/@minlat" />
<xsl:variable name="globmaxlat" select="/osm/bounds/@maxlat" />
<xsl:template match="/">
<svg version="1.1"
     baseProfile="full"
     xmlns="http://www.w3.org/2000/svg"
     xmlns:xlink="http://www.w3.org/1999/xlink"
     width="4000" height="3000">

<xsl:apply-templates select="//way[tag[(@k='building')]]"/>

</svg> 
</xsl:template>



<xsl:template match="way">

<polygon fill="yellow" stroke="black" stroke-width="2">
<xsl:attribute name="points"><xsl:apply-templates select="nd" /></xsl:attribute> 
</polygon>       

</xsl:template>



<xsl:template match="nd">
    <xsl:value-of select="(//node[@id=current()/@ref]/@lon - $globminlon) div ($globmaxlon - $globminlon) * 4000" />
    <xsl:text>,</xsl:text>
    <xsl:value-of select="3000 - (//node[@id=current()/@ref]/@lat - $globminlat ) div ($globmaxlat - $globminlat) * 3000" />
    <xsl:text> </xsl:text>
</xsl:template>

</xsl:stylesheet>



